cmake_minimum_required(VERSION 3.24)
project(212_cpp_game_FelixAtForsberg)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#message(NOTICE ${SDL2_INCLUDE_DIRS})

add_executable(212_cpp_game_FelixAtForsberg source/main.cpp source/system/window.cpp source/system/window.h source/system/error.cpp source/system/error.h source/game/Game.cpp source/game/Game.h source/game/Image.cpp source/game/Image.h)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_image::SDL2_image)