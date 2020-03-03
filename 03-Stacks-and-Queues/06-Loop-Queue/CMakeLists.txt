cmake_minimum_required(VERSION 3.10)
project(LoopQueue)

set(CMAKE_CXX_STANDARD 17)

add_executable(LoopQueue main.cpp Array.h Queue.h ArrayQueue.h LoopQueue.h)
