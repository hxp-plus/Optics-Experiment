cmake_minimum_required(VERSION 3.17)
project(optics_experiment C)

set(CMAKE_C_STANDARD 99)

add_executable(optics_experiment main.c generate_table.c generate_table.h main.h
        readcsv.c readcsv.h generate_document.c generate_document.h)