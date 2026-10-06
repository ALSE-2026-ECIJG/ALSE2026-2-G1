cmake_minimum_required(VERSION 3.10)
project(Alquiler)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(alquiler
    src/main.cpp
    src/Vehiculo.cpp
    src/Auto.cpp
    src/Bicicleta.cpp
    src/SistemaAlquiler.cpp
)
