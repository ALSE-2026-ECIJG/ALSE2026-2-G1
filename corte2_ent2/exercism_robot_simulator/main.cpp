#include <iostream>
#include <string>
#include <utility>

class Robot {
private:
    int x, y;
    int dir;

    static const int DX[4];
    static const int DY[4];
    static const std::string DIR_NAMES[4];

public:
    Robot() : x(0), y(0), dir(0) {}

    Robot(int startX, int startY, const std::string& direction) : x(startX), y(startY), dir(0) {
        for (int i = 0; i < 4; ++i) {
            if (DIR_NAMES[i] == direction) {
                dir = i;
                break;
            }
        }
    }

    void turnLeft()  { dir = (dir + 3) % 4; }
    void turnRight() { dir = (dir + 1) % 4; }
    void advance()   { x += DX[dir]; y += DY[dir]; }

    void move(const std::string& commands) {
        for (char c : commands) {
            if (c == 'L') turnLeft();
            else if (c == 'R') turnRight();
            else if (c == 'A') advance();
        }
    }

    std::pair<int, int> getPosition() const { return {x, y}; }
    std::string getDirection() const { return DIR_NAMES[dir]; }
};

const int Robot::DX[4] = {0, 1, 0, -1};
const int Robot::DY[4] = {1, 0, -1, 0};
const std::string Robot::DIR_NAMES[4] = {"NORTH", "EAST", "SOUTH", "WEST"};

void printState(const std::string& testName, const Robot& r) {
    auto pos = r.getPosition();
    std::cout << testName << " -> (" << pos.first << ", " << pos.second << ") "
              << r.getDirection() << std::endl;
}

int main() {
    std::cout << "=== Exercism: Robot Simulator ===\n" << std::endl;

    {
        Robot r;
        printState("Robot inicial", r);
    }

    {
        Robot r;
        r.move("R");
        printState("Comando \"R\"", r);
    }

    {
        Robot r;
        r.move("L");
        printState("Comando \"L\"", r);
    }

    {
        Robot r;
        r.move("A");
        printState("Comando \"A\"", r);
    }

    {
        Robot r;
        r.move("RAALAL");
        printState("Comando \"RAALAL\"", r);
    }

    {
        Robot r(7, 3, "NORTH");
        r.move("RAALAL");
        printState("Desde (7,3) NORTH con \"RAALAL\"", r);
    }

    {
        Robot r(0, 0, "EAST");
        r.move("LLRRAA");
        printState("Desde (0,0) EAST con \"LLRRAA\"", r);
    }

    std::cout << "\n=== Fin de las pruebas ===" << std::endl;
    return 0;
}
