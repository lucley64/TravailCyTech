cmake_minimum_required(VERSION 3.28)
project(ConstructeurDestructeur)

set(CMAKE_CXX_STANDARD 26)

add_executable(ConstructeurDestructeur main.cpp
        fraction.cpp
        fraction.h
        vector.cpp
        vector.h
        pair.h
        pair.cpp
        light.cpp
        light.h
        garland.cpp
        garland.h
        disk.cpp
        disk.h
        tower.cpp
        tower.h
        game.cpp
        game.h
)
