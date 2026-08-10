cmake_minimum_required(VERSION 4.2)
project(RelacjeObiektoweiDziedziczeniZawansowane2)

set(CMAKE_CXX_STANDARD 20)

add_executable(RelacjeObiektoweiDziedziczeniZawansowane2 main.cpp
        Dron.cpp
        Dron.h
        ModulKryptograficzny.cpp
        ModulKryptograficzny.h
        Operator.cpp
        Operator.h
        Eskadra.cpp
        Eskadra.h)
