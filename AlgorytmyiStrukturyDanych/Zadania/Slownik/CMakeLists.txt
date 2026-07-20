cmake_minimum_required(VERSION 3.20)
project(Slownik)

set(CMAKE_CXX_STANDARD 20)

# Lista wszystkich plików źródłowych .cpp biorących udział w kompilacji
add_executable(Slownik
        Program.cpp
        Common.cpp
        Dictionary.cpp
)