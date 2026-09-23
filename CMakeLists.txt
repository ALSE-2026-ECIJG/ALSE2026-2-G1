cmake_minimum_required(VERSION 3.10)
project(Taller2_ALSE)

set(CMAKE_CXX_STANDARD 17)

# Incluir directorios si es necesario
include_directories(.)

add_executable(design_twitter src/design_twitter.cpp)
add_executable(design_spreadsheet src/design_spreadsheet.cpp)
