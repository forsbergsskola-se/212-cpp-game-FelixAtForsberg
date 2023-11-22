# http://google.github.io/googletest/quickstart-cmake.html
#file(GLOB_RECURSE TEST_SOURCE_FILES "*.cpp")

set(TEST_SOURCE_FILES main.cpp test_file.cpp)

add_executable(${TEST_EXECUTABLE} ${TEST_SOURCE_FILES})

conditionally_log_files(LOG_TEST_SOURCE_FILES "TEST SOURCE FILES:" "${TEST_SOURCE_FILES}")

include_directories(${CMAKE_SOURCE_DIR}/source)

if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries( ${TEST_EXECUTABLE} PRIVATE SDL2::SDL2main)
endif()

# Link to the actual SDL2 library. SDL2::SDL2 is the shared SDL library, SDL2::SDL2-static is the static SDL libarary.
target_link_libraries(
        ${TEST_EXECUTABLE} PRIVATE
        GTest::gtest_main
#        SDL2::SDL2
#        SDL2_image::SDL2_image
       $<TARGET_OBJECTS:${GAME_LIBRARY}>
)