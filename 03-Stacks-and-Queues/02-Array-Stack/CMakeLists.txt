cmake_minimum_required(VERSION 3.10)
project(Array-Stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(Array-Stack main.cpp Array.h Stack.h ArrayStack.h)
