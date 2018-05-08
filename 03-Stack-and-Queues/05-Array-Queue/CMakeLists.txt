cmake_minimum_required(VERSION 3.10)
project(ArrayQueue)

set(CMAKE_CXX_STANDARD 11)

add_executable(ArrayQueue main.cpp Array.h Queue.h ArrayQueue.h)
