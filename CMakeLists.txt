cmake_minimum_required(VERSION 3.26)
project(212_cpp_game_FelixAtForsberg C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LOG_SOURCE_FILES_USED ON CACHE BOOL "Print source files list")
set(USE_MANUAL_SOURCE_FILES ON CACHE BOOL "Provide the order of source files rather than globbing source directory")

set(MANUAL_SOURCE_FILES
        source/main.cpp
        source/system/window.cpp
        source/system/window.h
        source/graphics/texture_factory.cpp
        source/graphics/texture_factory.h
)


# https://wiki.libsdl.org/SDL2/Installation
# https://wiki.libsdl.org/SDL2/README/cmake

#option(USE_VENDORED_SDL "Use vendored SDL" OFF)


#add_library(system SHARED /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib)

# https://stackoverflow.com/questions/45955272/modern-way-to-set-compiler-flags-in-cross-platform-cmake-project

# -nostdinc++ -nostdlib++ -isystem /usr/local/Cellar/llvm/17.0.3/include/c++/v1 -L /usr/local/Cellar/llvm/17.0.3/ -Wl,-rpath,/usr/local/Cellar/llvm/17.0.3/lib -lc++


#if(USE_VENDORED_SDL)
#    set(CMAKE_PREFIX_PATH /vendored)
#    find_package(SDL2       REQUIRED CONFIG REQUIRED COMPONENTS SDL2 NO_DEFAULT_PATH)
#    find_package(SDL2_image REQUIRED CONFIG REQUIRED COMPONENTS SDL2_image)

#    message(STATUS "SDL2 path: ${SDL2_DIR}")

#else()
    # 1. Look for a SDL2 package, 2. look for the SDL2 component and 3. fail if none can be found
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

    # 1. Look for a SDL2 package, 2. Look for the SDL2maincomponent and 3. DO NOT fail when SDL2main is not available
#    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

find_package(SDL2_image REQUIRED CONFIG COMPONENTS SDL2_image)
#endif()


file(GLOB_RECURSE SOURCE_FILES "source/*.cpp" "source/*.h")


if(LOG_SOURCE_FILES_USED)
    message(NOTICE "USE_MANUAL_SOURCE_FILES ${USE_MANUAL_SOURCE_FILES}")
message(NOTICE "=================================")
message(NOTICE "SOURCE FILES:")
foreach (FILE ${SOURCE_FILES})
    message(NOTICE "  \"${FILE}\"")
endforeach ()
endif ()

# Create your game executable target as usual
message(NOTICE "=================================")

if(USE_MANUAL_SOURCE_FILES)
    add_executable(
        ${PROJECT_NAME} MACOSX_BUNDLE
        ${MANUAL_SOURCE_FILES}
    )
else ()
    add_executable(
        ${PROJECT_NAME} MACOSX_BUNDLE
        ${SOURCE_FILES}
    )
endif ()

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
    if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
#    target_link_libraries(${PROJECT_NAME PRIVATE SDL2::SDL2main)
endif()

# Link to the actual SDL2 library. SDL2::SDL2 is the shared SDL library, SDL2::SDL2-static is the static SDL libarary.
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)

#target_link_options(${PROJECT_NAME} PRIVATE "-v")

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/source/texture.png
                ${CMAKE_CURRENT_BINARY_DIR}/source/texture.png
        )