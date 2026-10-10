cmake_minimum_required(VERSION 3.10)
project(ProyectoUnificado)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(BibliotecaApp
    src/main.cpp
    src/Libro.cpp
    src/Biblioteca.cpp
    src/Vehiculo.cpp
    src/SistemaAlquiler.cpp
)
