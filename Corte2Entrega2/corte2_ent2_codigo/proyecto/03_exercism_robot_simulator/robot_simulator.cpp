#include "robot_simulator.h"

namespace robot_simulator {

Robot::Robot() : position_{0, 0}, bearing_{Bearing::NORTH} {}

Robot::Robot(std::pair<int, int> position, Bearing bearing)
    : position_{position}, bearing_{bearing} {}

std::pair<int, int> Robot::get_position() const {
    return position_;
}

Bearing Robot::get_bearing() const {
    return bearing_;
}

void Robot::turn_right() {
    int next_bearing = (static_cast<int>(bearing_) + 1) % 4;
    bearing_ = static_cast<Bearing>(next_bearing);
}

void Robot::turn_left() {
    int next_bearing = (static_cast<int>(bearing_) + 3) % 4;
    bearing_ = static_cast<Bearing>(next_bearing);
}

void Robot::advance() {
    switch (bearing_) {
        case Bearing::NORTH:
            position_.second++;
            break;
        case Bearing::EAST:
            position_.first++;
            break;
        case Bearing::SOUTH:
            position_.second--;
            break;
        case Bearing::WEST:
            position_.first--;
            break;
    }
}

void Robot::execute_sequence(const std::string& sequence) {
    for (char cmd : sequence) {
        switch (cmd) {
            case 'R':
                turn_right();
                break;
            case 'L':
                turn_left();
                break;
            case 'A':
                advance();
                break;
        }
    }
}

}
