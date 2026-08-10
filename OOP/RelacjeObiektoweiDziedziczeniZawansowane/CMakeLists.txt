cmake_minimum_required(VERSION 4.2)
project(RelacjeObiektoweiDziedziczeniZawansowane)

set(CMAKE_CXX_STANDARD 20)

add_executable(RelacjeObiektoweiDziedziczeniZawansowane main.cpp
        Sejf.cpp
        Sejf.h
        ZamekCyfrowy.cpp
        ZamekCyfrowy.h
        Osoba.cpp
        Osoba.h
        ZasobyWarażlie.cpp
        ZasobyWarażlie.h)
