cmake_minimum_required(VERSION 3.10)
project(BibliotecaSystem)

set(CMAKE_CXX_STANDARD 17)

# Incluir los headers
include_directories(include)

# Definir el ejecutable con sus archivos fuente
add_executable(BibliotecaApp
    src/main.cpp
    src/Libro.cpp
    src/Biblioteca.cpp
)
