cmake_minimum_required(VERSION 3.26)

project(SDLGameProject)

# ===============================================
# =============== Configuration

set(GAME_LOG_SOURCE_FILES         ON CACHE BOOL "Print game executable source files")

set(GAME_LIBRARY_LOG_SOURCE_FILES ON CACHE BOOL "Print game library source files") # Game library target that tests link against

set(TEST_LOG_SOURCE_FILES         ON CACHE BOOL "Print test source files")


set(USE_VENDORED_SDL2          ON CACHE BOOL "Prefer vendored SDL2" FORCE)


# "INTERNAL": Don't show in CMakeGUI & always override (implies FORCE)
set(GAME_EXECUTABLE     "SDLGame"      CACHE INTERNAL "Name the game executable and respective targets will use")
set(GAME_LIBRARY        "SDLGame_lib"  CACHE INTERNAL "Name the game library and respective targets will use")
set(TEST_EXECUTABLE     "SDLGame_test" CACHE INTERNAL "Name the test executable and respective targets will use")

# ===============================================
# =============== CMake Setup

enable_language(C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set( LOG_CMAKE_VERBOSE ON CACHE BOOL "Pass verbose flags to CMake")
set(LOG_LINKER_VERBOSE ON CACHE BOOL "Pass verbose flag to linker")

if(LOG_CMAKE_VERBOSE)
    set(CMAKE_VERBOSE_MAKEFILE ON)
#    set(CMAKE_BUILD_TYPE Debug)
endif()

if(LOG_LINKER_VERBOSE)
    set(CMAKE_EXE_LINKER_FLAGS       "${CMAKE_EXE_LINKER_FLAGS} -v")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -v")
    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -v")
endif()



# ===============================================
# =============== Locate SDL2 Packages - which other targets can use to link against

# https://wiki.libsdl.org/SDL2/Installation
# https://wiki.libsdl.org/SDL2/README/cmake
if (USE_VENDORED_SDL2)
find_package(SDL2       REQUIRED CONFIG REQUIRED COMPONENTS SDL2       PATHS "vendored/" NO_DEFAULT_PATH)
find_package(SDL2_image REQUIRED CONFIG REQUIRED COMPONENTS SDL2_image PATHS "vendored/" NO_DEFAULT_PATH)
find_package(SDL2_ttf   REQUIRED CONFIG REQUIRED COMPONENTS SDL2_ttf   PATHS "vendored/" NO_DEFAULT_PATH)
else()
find_package(SDL2       REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2_image REQUIRED CONFIG REQUIRED COMPONENTS SDL2_image)
find_package(SDL2_ttf   REQUIRED CONFIG REQUIRED COMPONENTS SDL2_ttf)
endif()

# ===============================================
# =============== Utility Logging Function

# not a macro because we don't want to pollute scope
function (conditionally_log_files ARG_CONDITION ARG_TITLE ARG_FILE_LIST)
    list(LENGTH ARG_FILE_LIST FILE_LIST_LENGTH)
    if(ARG_CONDITION)

        message(NOTICE "=================================================")
        message(NOTICE "File listing initiated from:\n ${CMAKE_CURRENT_LIST_FILE}")
        message(NOTICE "=================================================")
        message(NOTICE "${FILE_LIST_LENGTH} - ${ARG_TITLE}")
        foreach(FILE ${ARG_FILE_LIST})
            message(NOTICE "\"" "${FILE}" "\"")
        endforeach()
        message(NOTICE "=================================================\n")

    endif()
endfunction()

# ===============================================
# =============== GoogleTest - Fetch and declare test dependencies from Github

#https://www.jetbrains.com/help/clion/creating-google-test-run-debug-configuration-for-test.html

# http://google.github.io/googletest/quickstart-cmake.html
# https://cmake.org/cmake/help/latest/module/FetchContent.html
include(FetchContent)

# GIT_TAG:  git show-ref --tags -d

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571 # Release v1.14.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# ===============================================
# =============== Include CMakeLists.txt for game/testing

add_subdirectory(source)
add_subdirectory(tests)

