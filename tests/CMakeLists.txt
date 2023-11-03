# http://google.github.io/googletest/quickstart-cmake.html
file(GLOB_RECURSE SOURCE_FILES_TEST "*.cpp")
#enable_language(CXX)

set(TEST_EXECUTABLE_NAME "${PROJECT_NAME}_tests")

add_executable(${TEST_EXECUTABLE_NAME} ${SOURCE_FILES_TEST})

conditionally_log_files(LOG_SOURCE_FILES_TEST "TEST SOURCE FILES:" ${SOURCE_FILES_TEST})

target_link_libraries(
  ${TEST_EXECUTABLE_NAME}
  GTest::gtest_main
)
