cmake_minimum_required(VERSION 3.28)
project(TemplateSTL)

set(CMAKE_CXX_STANDARD 26)

add_executable(TemplateSTL main.cpp
    my_vector.h
fraction.cpp
fraction.h)
