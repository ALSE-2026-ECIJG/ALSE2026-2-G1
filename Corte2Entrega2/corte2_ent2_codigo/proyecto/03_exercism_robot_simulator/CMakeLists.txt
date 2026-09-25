add_library(RobotSimulator robot_simulator.cpp)
target_include_directories(RobotSimulator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(robot_simulator main.cpp)
target_link_libraries(robot_simulator PRIVATE RobotSimulator)
