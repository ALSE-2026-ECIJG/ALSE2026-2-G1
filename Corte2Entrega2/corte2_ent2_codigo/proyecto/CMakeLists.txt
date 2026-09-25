cmake_minimum_required(VERSION 3.10)
project(Corte2_Entrega2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Cada subcarpeta define su propia librería + ejecutable de demostración.
# "cmake --build ." desde la carpeta build compila TODOS los targets
# de una sola vez: design_twitter, design_spreadsheet, robot_simulator,
# queen_attack y sphere_demo.
add_subdirectory(01_leetcode_design_twitter)
add_subdirectory(02_leetcode_design_spreadsheet)
add_subdirectory(03_exercism_robot_simulator)
add_subdirectory(04_exercism_queen_attack)
add_subdirectory(05_clase_sphere)
