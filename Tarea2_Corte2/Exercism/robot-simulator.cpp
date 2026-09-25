#include <iostream>
#include <utility>
#include <string>

namespace robot_simulator {

enum Bearing {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

class Robot {
private:
    std::pair<int, int> position;
    Bearing direction;

public:
    Robot(std::pair<int, int> pos, Bearing dir) : position(pos), direction(dir) {}

    std::pair<int, int> get_position() const {
        return position;
    }

    Bearing get_bearing() const {
        return direction;
    }

    void turn_right() {
        direction = static_cast<Bearing>((direction + 1) % 4);
    }

    void turn_left() {
        direction = static_cast<Bearing>((direction + 3) % 4);
    }

    void advance() {
        switch (direction) {
            case NORTH: position.second++; break;
            case EAST:  position.first++; break;
            case SOUTH: position.second--; break;
            case WEST:  position.first--; break;
        }
    }

    void execute_sequence(const std::string& instructions) {
        for (char instruction : instructions) {
            if (instruction == 'R') turn_right();
            else if (instruction == 'L') turn_left();
            else if (instruction == 'A') advance();
        }
    }
};

} // namespace robot_simulator

// Función principal para probar el robot
int main() {
    robot_simulator::Robot robot({7, 3}, robot_simulator::Bearing::NORTH);
    robot.execute_sequence("RAALAL");
    
    auto pos = robot.get_position();
    std::cout << "Posicion final X: " << pos.first << ", Y: " << pos.second << std::endl;
    return 0;
}
