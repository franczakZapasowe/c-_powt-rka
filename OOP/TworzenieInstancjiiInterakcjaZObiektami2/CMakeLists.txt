cmake_minimum_required(VERSION 3.10)

project(powtorka)

set(CMAKE_CXX_STANDARD 20)

add_executable(projekt main.cpp
        ProbkaAudio.cpp
        ProbkaAudio.h
        SilnikDSP.cpp
        SilnikDSP.h)

