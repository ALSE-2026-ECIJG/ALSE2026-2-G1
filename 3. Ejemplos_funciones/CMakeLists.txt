cmake_minimum_required(VERSION 3.10)

project(EjemplosFunciones LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(arguments arguments.cpp)
add_executable(arrays arrays.cpp)
add_executable(functions functions.cpp)
