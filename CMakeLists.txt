cmake_minimum_required(VERSION 3.24)
project(212_cpp_game_FelixAtForsberg)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(212_cpp_game_FelixAtForsberg main.cpp)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})