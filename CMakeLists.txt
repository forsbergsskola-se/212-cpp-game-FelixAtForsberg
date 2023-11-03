cmake_minimum_required(VERSION 3.26)
project(SDLGame)

enable_language(C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LOG_SOURCE_FILES_TEST ON CACHE BOOL "Print source files")
set(LOG_SOURCE_FILES_GAME ON CACHE BOOL "Print source files")

function (conditionally_log_files ARG_CONDITION ARG_TITLE ARG_FILE_LIST)
    list(LENGTH ARG_FILE_LIST FILE_LIST_LENGTH)
    if(ARG_CONDITION)

        message(NOTICE "=================================================")
        message(NOTICE "File listing initiated from:\n ${CMAKE_CURRENT_LIST_FILE}")
        message(NOTICE "=================================================")
        message(NOTICE "${FILE_LIST_LENGTH} - ${ARG_TITLE}")
        foreach(FILE ${ARG_FILE_LIST})
            message(NOTICE "\"" ${FILE} "\"")
        endforeach()
        message(NOTICE "=================================================\n")

    endif()
endfunction()

#conditionally_log_files(LOG_SOURCE_FILES_TEST "TEST SOURCE FILES:" ${SOURCE_FILES_TEST})

#https://www.jetbrains.com/help/clion/creating-google-test-run-debug-configuration-for-test.html


# http://google.github.io/googletest/quickstart-cmake.html
# https://cmake.org/cmake/help/latest/module/FetchContent.html
include(FetchContent)

# git show-ref --tags -d

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571 # Release v1.14.0
)

FetchContent_MakeAvailable(googletest)
enable_testing()


add_subdirectory(source)
add_subdirectory(tests)
