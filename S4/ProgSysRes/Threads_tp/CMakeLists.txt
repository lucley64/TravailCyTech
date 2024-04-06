cmake_minimum_required(VERSION 3.28)
project(Threads_tp C)

set(CMAKE_C_STANDARD 23)

add_executable(Threads_tp main.c)

find_package(Threads REQUIRED)

target_link_libraries(Threads_tp PUBLIC Threads::Threads)
