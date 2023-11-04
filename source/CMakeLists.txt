cmake_minimum_required(VERSION 3.26)


# ===============================================
# =============== Game Library - For linking tests to game functions

file(GLOB_RECURSE GAME_LIBRARY_SOURCE_FILES "*.cpp" "*.h")
# use game files without entry point (main.cpp)
list(FILTER GAME_LIBRARY_SOURCE_FILES EXCLUDE REGEX ".*\\main.cpp$") # remove main.cpp

conditionally_log_files(${GAME_LIBRARY_LOG_SOURCE_FILES} "GAME LIBRARY FILES:" "${GAME_LIBRARY_SOURCE_FILES}")

add_library(${GAME_LIBRARY} OBJECT ${GAME_LIBRARY_SOURCE_FILES})

# ===============================================
# =============== Game Executable - Reuse library and link to executable


# add main.cpp and reuse object files built from source files
set(GAME_SOURCE_FILES main.cpp $<TARGET_OBJECTS:${GAME_LIBRARY}>)
conditionally_log_files(${GAME_LOG_SOURCE_FILES} "GAME SOURCE FILES:" "${GAME_SOURCE_FILES}")

# Create game executable target
add_executable(
    ${GAME_EXECUTABLE} MACOSX_BUNDLE ${GAME_SOURCE_FILES}
)



# ===============================================
# =============== SDL2 - Link to Game Executable + Library

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries( ${GAME_EXECUTABLE} PRIVATE SDL2::SDL2main)
    target_link_libraries( ${GAME_LIBRARY} PRIVATE SDL2::SDL2main)
endif()

# Link to the actual SDL2 library. SDL2::SDL2 is the shared SDL library, SDL2::SDL2-static is the static SDL libarary.
target_link_libraries( ${GAME_EXECUTABLE} PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)
target_link_libraries( ${GAME_LIBRARY}    PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)

# ===============================================
# =============== Copy '/assets/' from /source/assets to 'app'/Contents/

add_custom_command(
    TARGET ${GAME_EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "$<TARGET_PROPERTY:${GAME_EXECUTABLE},SOURCE_DIR>/assets"
        "$<TARGET_PROPERTY:${GAME_EXECUTABLE},BINARY_DIR>/${GAME_EXECUTABLE}.app/Contents/MacOS/Resources"
)
