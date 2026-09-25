cmake_minimum_required(VERSION 3.10)
project(Tarea2_Corte2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(twitter_exe LeetCode/twitter.cpp)
add_executable(spreadsheet_exe LeetCode/spreadsheet.cpp)

add_executable(robot_exe Exercism/robot-simulator.cpp)
add_executable(queen_exe Exercism/queen-attack.cpp)

add_executable(sphere_exe sphere/main.cpp sphere/sphere.cpp)
