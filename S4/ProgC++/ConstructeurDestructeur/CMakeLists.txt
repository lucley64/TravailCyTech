cmake_minimum_required(VERSION 3.28)
project(ConstructeurDestructeur)

set(CMAKE_CXX_STANDARD 26)

add_executable(ConstructeurDestructeur main.cpp
        fraction.cpp
        fraction.h
        vector.cpp
        vector.h
)
