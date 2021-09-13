cmake_minimum_required(VERSION 2.8)
project(CSE_Project1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(includes/iostream)
include_directories(includes/string)
set(CMAKE_CXX_STANDARD 14)

add_executable(CSE_Project1 main.cpp)
