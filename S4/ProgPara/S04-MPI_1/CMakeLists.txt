cmake_minimum_required(VERSION 3.28)
project(S04_MPI_1 C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(S04_MPI_1 main.c)

find_package(MPI)
if (MPI_FOUND)
    target_link_libraries(S04_MPI_1 PUBLIC MPI::MPI_C)
endif ()
