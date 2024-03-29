cmake_minimum_required(VERSION 3.28)
project(S05_MPI_2 C)

set(CMAKE_C_STANDARD 23)

add_executable(S05_MPI_2 main.c)

find_package(MPI REQUIRED)

target_link_libraries(S05_MPI_2 MPI::MPI_C)
