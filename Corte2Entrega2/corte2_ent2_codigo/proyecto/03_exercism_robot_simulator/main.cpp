/**
 * @file main.cpp
 * @brief Demostración del ejercicio robot-simulator de Exercism.
 */
#include <iostream>
#include "robot_simulator.h"

using robot_simulator::Bearing;
using robot_simulator::Robot;

std::string bearing_name(Bearing b) {
    switch (b) {
        case Bearing::NORTH: return "NORTH";
        case Bearing::EAST:  return "EAST";
        case Bearing::SOUTH: return "SOUTH";
        case Bearing::WEST:  return "WEST";
    }
    return "?";
}

void report(const Robot& r, const std::string& label) {
    auto [x, y] = r.get_position();
    std::cout << label << " -> posicion (" << x << ", " << y
              << "), orientacion " << bearing_name(r.get_bearing()) << "\n";
}

int main() {
    Robot r1;
    report(r1, "Robot recien creado");

    Robot r2({0, 0}, Bearing::NORTH);
    r2.turn_right();
    report(r2, "Tras turn_right() desde NORTH");

    Robot r3({0, 0}, Bearing::NORTH);
    r3.advance();
    report(r3, "Tras advance() desde NORTH en (0,0)");

    Robot r4({0, 0}, Bearing::NORTH);
    r4.execute_sequence("LAAARALA");
    report(r4, "Tras execute_sequence(\"LAAARALA\")");  // esperado: (-4,1) WEST

    return 0;
}
