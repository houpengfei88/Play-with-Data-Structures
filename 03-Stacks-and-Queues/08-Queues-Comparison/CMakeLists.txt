cmake_minimum_required(VERSION 3.10)
project(Queues-Comparison)

set(CMAKE_CXX_STANDARD 17)

add_executable(Queues-Comparison main.cpp Array.h Queue.h ArrayQueue.h LoopQueue.h)
