cmake_minimum_required(VERSION 3.28)
project(Project C)

set(CMAKE_C_STANDARD 23)

add_executable(Project main.c
        PartA/part_a.h
        PartA/part_a.c)

find_package(Threads REQUIRED)

target_link_libraries(Project Threads::Threads m)
