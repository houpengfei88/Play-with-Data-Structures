cmake_minimum_required(VERSION 3.10)
project(LinkedListSet)

set(CMAKE_CXX_STANDARD 11)

add_executable(LinkedListSet main.cpp LinkedListSet.h Set.h LinkedList.h FileOperation.h)
