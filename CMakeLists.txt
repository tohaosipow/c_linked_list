cmake_minimum_required(VERSION 3.9)
project(lab2 C)

set(CMAKE_C_STANDARD 99)

add_library(lab2-list list.c list.h)
add_library(lab2-menu listmenu.c listmenu.h)
add_executable(lab2-main main.c)
target_link_libraries(lab2-main lab2-list)
target_link_libraries(lab2-main lab2-menu)