cmake_minimum_required(VERSION 3.0.0)
project(tetris)

set(CMAKE_C_STANDARD 11)

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC tetrislib)