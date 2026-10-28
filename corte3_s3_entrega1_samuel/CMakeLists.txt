cmake_minimum_required(VERSION 3.10)
project(corte3_s3_entrega1_samuel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ejercicio 1: Underground System
add_executable(ej1_underground ej1_underground/main.cpp)

# Ejercicio 2: ATM Machine
add_executable(ej2_atm ej2_atm/main.cpp)

# Ejercicio 3: Auction System
add_executable(ej3_auction ej3_auction/main.cpp)

# Ejercicio 4: Meetup
add_executable(ej4_meetup ej4_meetup/main.cpp)

# Ejercicio 5: Clock
add_executable(ej5_clock ej5_clock/main.cpp ej5_clock/clock.cpp)
