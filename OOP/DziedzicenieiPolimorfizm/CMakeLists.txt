cmake_minimum_required(VERSION 3.10)

project(Polimorfizm)

set(CMAKE_CXX_STANDRAD 20)

add_executable(polimorfizm main.cpp
        Wtyczka.cpp
        Wtyczka.h
        Korektor.cpp
        Korektor.h
        Kompresor.cpp
        Kompresor.h
        Wielopasmowy.cpp
        Wielopasmowy.h
        Diagnostyczna.cpp
        Diagnostyczna.h)

