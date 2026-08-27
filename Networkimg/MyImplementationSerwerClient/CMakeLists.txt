cmake_minimum_required(VERSION 4.2)
project(MyImplementationSerwerClient)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyImplementationSerwerClient serwer.cpp
        klient.cpp)
