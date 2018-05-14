cmake_minimum_required(VERSION 3.10)
project(BSTMap)

set(CMAKE_CXX_STANDARD 11)

add_executable(BSTMap main.cpp BSTMap.h FileOperation.h Map.h)
