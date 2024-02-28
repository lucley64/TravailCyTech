cmake_minimum_required(VERSION 3.28)
project(S03_OpenMP_3 C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(S03_OpenMP_3 main.c)

find_package(OpenMP)
if(OpenMP_FOUND)
    target_link_libraries(S03_OpenMP_3 PUBLIC m OpenMP::OpenMP_C)
else ()
    target_link_libraries(S03_OpenMP_3 m)
endif()
