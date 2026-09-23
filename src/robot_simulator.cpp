#pragma once

#include <utility>
#include <string>

namespace robot_simulator {

enum Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Robot {
private:
    std::pair<int, int> position;
    Bearing bearing;

public:
    Robot(std::pair<int, int> pos = {0, 0}, Bearing b = NORTH) 
        : position(pos), bearing(b) {}

    std::pair<int, int> get_position() const {
        return position;
    }

    Bearing get_bearing() const {
        return bearing;
    }

    void turn_right() {
        bearing = static_cast<Bearing>((bearing + 1) % 4);
    }

    void turn_left() {
        bearing = static_cast<Bearing>((bearing + 3) % 4);
    }

    void advance() {
        if (bearing == NORTH) {
            position.second++;
        } else if (bearing == EAST) {
            position.first++;
        } else if (bearing == SOUTH) {
            position.second--;
        } else if (bearing == WEST) {
            position.first--;
        }
    }

    void simulate(const std::string& instructions) {
        for (char instruction : instructions) {
            if (instruction == 'R') {
                turn_right();
            } else if (instruction == 'L') {
                turn_left();
            } else if (instruction == 'A') {
                advance();
            }
        }
    }
};

} // namespace robot_simulator


