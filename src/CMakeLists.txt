cmake_minimum_required(VERSION 3.0.0)
project(tetris VERSION 0.1.0)

find_package(raylib 4.2 REQUIRED)

add_library(tetrislib SHARED Board.cpp CustomRaylib.cpp Game.cpp Tetromino.cpp)
target_link_libraries(tetrislib raylib)
target_include_directories(tetrislib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)