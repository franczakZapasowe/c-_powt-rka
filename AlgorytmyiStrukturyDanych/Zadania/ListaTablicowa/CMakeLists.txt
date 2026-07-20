cmake_minimum_required(VERSION 3.20)
project(ListaTablicowa)

set(CMAKE_CXX_STANDARD 20)

# Tutaj musisz wymienić wszystkie pliki .cpp, które biorą udział w kompilacji
add_executable(ListaTablicowa
        Program.cpp
        Common.cpp
        ListA.cpp
        ListATest.cpp
)