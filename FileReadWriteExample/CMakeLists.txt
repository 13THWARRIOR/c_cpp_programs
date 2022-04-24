cmake_minimum_required(VERSION 3.20)
project(FileReadWriteExample C)

set(CMAKE_C_STANDARD 11)

add_executable(FileReadWriteExample main.c)
configure_file(filetoread.txt ${CMAKE_CURRENT_BINARY_DIR})
