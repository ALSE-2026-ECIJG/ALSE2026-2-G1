cmake_minimum_required(VERSION 3.10)

project(EjemploOperTypes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(types types.cpp)
add_executable(operators operators.cpp)
