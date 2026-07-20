cmake_minimum_required(VERSION 3.20)
project(StosIKolejka)

set(CMAKE_CXX_STANDARD 20)

# Lista wszystkich plików źródłowych biorących udział w kompilacji
add_executable(StosIKolejka
        Program.cpp
        Common.cpp
        KolejkaStosA.cpp
        KolejkaStosP.cpp
        Program.cpp
        KolejkaStosA.h
)