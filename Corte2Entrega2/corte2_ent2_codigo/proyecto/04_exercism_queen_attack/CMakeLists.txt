add_library(QueenAttack queen_attack.cpp)
target_include_directories(QueenAttack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(queen_attack main.cpp)
target_link_libraries(queen_attack PRIVATE QueenAttack)
