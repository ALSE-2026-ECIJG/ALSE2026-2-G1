cmake_minimum_required(VERSION 3.10)
project(Biblioteca)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(biblioteca
    src/main.cpp
    src/Libro.cpp
    src/Biblioteca.cpp
)
