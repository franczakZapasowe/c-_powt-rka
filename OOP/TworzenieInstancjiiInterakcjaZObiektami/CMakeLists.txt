cmake_minimum_required(VERSION 3.10)

project(Zadanie)

set (CMAKE_CXX_STANDARD 20)

add_executable(zadanie main.cpp
        dron.cpp
        dron.h
        Testy.cpp
        Testy.h)