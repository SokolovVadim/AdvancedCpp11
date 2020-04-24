
cmake_minimum_required(VERSION 3.10.2)
set (CMAKE_CXX_STANDARD 11)

project(main)
add_executable(main main.cpp)
target_include_directories(main PUBLIC ./)
