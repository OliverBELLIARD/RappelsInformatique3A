cmake_minimum_required(VERSION 3.29)
project(rappels_info C)

set(CMAKE_C_STANDARD 17)

add_executable(rappels_info main.c
        fonctions.h
        nombres.txt)
