cmake_minimum_required(VERSION 3.10)
project(Taller2_Entrega3_ALSE)

set(CMAKE_CXX_STANDARD 17)

# Incluir directorios si es necesario
include_directories(.)

# Ejecutables de esta entrega actual
add_executable(design_authentication_manager src/design_authentication_manager.cpp)
add_executable(exam_score_tracker src/exam_score_tracker.cpp)
add_executable(crypto_square src/crypto_square.cpp)
add_executable(bank_account src/bank_account.cpp)
