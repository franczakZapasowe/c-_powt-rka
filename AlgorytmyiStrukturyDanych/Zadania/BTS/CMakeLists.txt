cmake_minimum_required(VERSION 4.2)
project(BTS)

set(CMAKE_CXX_STANDARD 20)

add_executable(BTS
        BST.cpp
        BSTTest.cpp
        Common.cpp
        Program.cpp
        BSTTest.h)
