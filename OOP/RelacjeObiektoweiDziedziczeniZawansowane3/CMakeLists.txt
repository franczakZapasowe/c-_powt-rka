cmake_minimum_required(VERSION 4.2)
project(RelacjeObiektoweiDziedziczeniZawansowane3)

set(CMAKE_CXX_STANDARD 20)

add_executable(RelacjeObiektoweiDziedziczeniZawansowane3 main.cpp
        ModulAwioniki.cpp
        ModulAwioniki.h
        Kamera.cpp
        Kamera.h
        Nadajnik.cpp
        Nadajnik.h
        DronZwiadowczy.cpp
        DronZwiadowczy.h)
