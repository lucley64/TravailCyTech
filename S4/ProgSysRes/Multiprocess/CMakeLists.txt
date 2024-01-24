cmake_minimum_required(VERSION 3.27)
project(Multiprocess C)

set(CMAKE_C_STANDARD 23)

add_executable(Multiprocess main.c
        compte_argc.c)
