#include <iostream>
#include <string>

// Definimos las direcciones en orden horario para facilitar los giros
enum Direction { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3 };

class Robot {
private:
    int x, y;
    Direction bearing;

public:
    Robot(int initX, int initY, Direction initBearing) {
        x = initX;
        y = initY;
        bearing = initBearing;
    }

    void turnRight() {
        bearing = static_cast<Direction>((bearing + 1) % 4);
    }

    void turnLeft() {
        bearing = static_cast<Direction>((bearing + 3) % 4);
    }

    void advance() {
        switch (bearing) {
            case NORTH: y++; break;
            case EAST:  x++; break;
            case SOUTH: y--; break;
            case WEST:  x--; break;
        }
    }

    void simulate(const std::string& instructions) {
        for (char cmd : instructions) {
            if (cmd == 'R') {
                turnRight();
            } else if (cmd == 'L') {
                turnLeft();
            } else if (cmd == 'A') {
                advance();
            }
        }
    }

    int getX() const { return x; }
    int getY() const { return y; }
    
    std::string getBearingString() const {
        switch (bearing) {
            case NORTH: return "north";
            case EAST: return "east";
            case SOUTH: return "south";
            case WEST: return "west";
        }
        return "";
    }
};

// Función principal (main) para probar el simulador en la terminal
int main() {
    // Prueba basada en el ejemplo: empieza en {7, 3} mirando al norte
    Robot robot(7, 3, NORTH);
    
    // Ejecutamos la secuencia "RAALAL"[cite: 8]
    robot.simulate("RAALAL");

    std::cout << "Posición final: {" << robot.getX() << ", " << robot.getY() << "}" << std::endl;
    std::cout << "Orientación final: " << robot.getBearingString() << " (Esperado: west)" << std::endl;

    return 0;
}
