cmake_minimum_required(VERSION 3.10)
project(Corte2_Entrega3 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# LeetCode
add_subdirectory(leetcode/1797_authentication_manager)
add_subdirectory(leetcode/3709_exam_scores_tracker)

# Exercism
add_subdirectory(exercism/crypto_square)
add_subdirectory(exercism/bank_account)
