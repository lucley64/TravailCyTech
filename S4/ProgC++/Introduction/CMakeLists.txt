cmake_minimum_required(VERSION 3.27)
project(Introduction)

set(CMAKE_CXX_STANDARD 23)

add_executable(Introduction main.cpp
        light.cpp
        light.h
        vector.cpp
        vector.h)
