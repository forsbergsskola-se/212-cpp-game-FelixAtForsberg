cmake_minimum_required(VERSION 3.26)
project(212_cpp_game_FelixAtForsberg C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# https://wiki.libsdl.org/SDL2/Installation
# https://wiki.libsdl.org/SDL2/README/cmake

option(USE_VENDORED_SDL "Use vendored SDL" OFF)

#add_library(system SHARED /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib)


# https://stackoverflow.com/questions/45955272/modern-way-to-set-compiler-flags-in-cross-platform-cmake-project

# -nostdinc++ -nostdlib++ -isystem /usr/local/Cellar/llvm/17.0.3/include/c++/v1 -L /usr/local/Cellar/llvm/17.0.3/ -Wl,-rpath,/usr/local/Cellar/llvm/17.0.3/lib -lc++


if(USE_VENDORED_SDL)
    add_subdirectory(vendored/ EXCLUDE_FROM_ALL)
else()
    # 1. Look for a SDL2 package, 2. look for the SDL2 component and 3. fail if none can be found
    find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

    # 1. Look for a SDL2 package, 2. Look for the SDL2maincomponent and 3. DO NOT fail when SDL2main is not available
#    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

    find_package(SDL2_image REQUIRED CONFIG COMPONENTS SDL2_image)
endif()


file(GLOB_RECURSE source_files "source/*.cpp" "source/*.h")
# Create your game executable target as usual
add_executable(
        212_cpp_game_FelixAtForsberg MACOSX_BUNDLE
        ${source_files}
#        source/main.cpp
#        source/system/window.cpp
#        source/system/window.h
)


# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
#    target_link_libraries(212_cpp_game_FelixAtForsberg PRIVATE SDL2::SDL2main)
endif()

# Link to the actual SDL2 library. SDL2::SDL2 is the shared SDL library, SDL2::SDL2-static is the static SDL libarary.
target_link_libraries(212_cpp_game_FelixAtForsberg PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)