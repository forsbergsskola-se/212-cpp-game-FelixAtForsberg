
cmake_minimum_required(VERSION 3.26)
project(Game C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LOG_SOURCE_FILES_USED ON CACHE BOOL "Print source files list")
#set(CMAKE_SOURCE_DIR "/source/")
# https://wiki.libsdl.org/SDL2/Installation
# https://wiki.libsdl.org/SDL2/README/cmake

# 1. Look for a SDL2 package, 2. look for the SDL2 component and 3. fail if none can be found
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

# 1. Look for a SDL2 package, 2. Look for the SDL2maincomponent and 3. DO NOT fail when SDL2main is not available
#    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
find_package(SDL2_image REQUIRED CONFIG COMPONENTS SDL2_image)

file(GLOB_RECURSE SOURCE_FILES "source/*.cpp" "source/*.h")

if(LOG_SOURCE_FILES_USED)
    message(NOTICE "USE_MANUAL_SOURCE_FILES ${USE_MANUAL_SOURCE_FILES}")
    message(NOTICE "=================================")
    message(NOTICE "SOURCE FILES:")

    foreach(FILE ${SOURCE_FILES})
        message(NOTICE "  \"${FILE}\"")
    endforeach()
    message(NOTICE "=================================")
endif ()

# Create your game executable target as usual
add_executable(
${PROJECT_NAME} MACOSX_BUNDLE
    ${SOURCE_FILES}
)

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)
endif()

# Link to the actual SDL2 library. SDL2::SDL2 is the shared SDL library, SDL2::SDL2-static is the static SDL libarary.
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)



#        "$<TARGET_PROPERTY:${PROJECT_NAME},SOURCE_DIR>/assets"
# Copy assets/ over
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "$<TARGET_PROPERTY:${PROJECT_NAME},SOURCE_DIR>/source/assets"
        "$<TARGET_PROPERTY:${PROJECT_NAME},BINARY_DIR>/Game.app/Contents/MacOS/Resources"
)