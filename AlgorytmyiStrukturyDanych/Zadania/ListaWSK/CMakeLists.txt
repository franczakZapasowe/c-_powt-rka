cmake_minimum_required(VERSION 4.2)
project(ListaWSK)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListaWSK Program.cpp Common.cpp ListP.cpp ListPTest.cpp)
