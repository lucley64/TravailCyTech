cmake_minimum_required(VERSION 3.28)
project(HeritagePolymorphisme)

set(CMAKE_CXX_STANDARD 26)

add_executable(HeritagePolymorphisme main.cpp
        CM/person.cpp
        CM/person.h
        CM/student.cpp
        CM/student.h
        CM/polygon.cpp
        CM/polygon.h
        CM/rectangle.cpp
        CM/rectangle.h
        CM/triangle.cpp
        CM/triangle.h
        garlands/garland.cpp
        garlands/garland.h
        garlands/light.cpp
        garlands/light.h
        garlands/electric.cpp
        garlands/electric.h
        filesystem/element.h
        filesystem/directory.cpp
        filesystem/directory.h
        filesystem/file.h
        filesystem/encoding.h
        filesystem/text.cpp
        filesystem/text.h
        filesystem/image.cpp
        filesystem/image.h
        filesystem/video.cpp
        filesystem/video.h)
