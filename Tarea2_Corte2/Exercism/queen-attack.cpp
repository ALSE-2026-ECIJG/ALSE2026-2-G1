#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>

namespace queen_attack {

class queen {
private:
    std::pair<int, int> pos;
public:
    
    queen(std::pair<int, int> position) : pos(position) {
        if (pos.first < 0 || pos.first > 7 || pos.second < 0 || pos.second > 7) {
            throw std::domain_error("Posicion fuera del tablero de ajedrez.");
        }
    }

    // Obtener coordenadas
    std::pair<int, int> coord() const {
        return pos;
    }

    // Verificar si se pueden atacar
    bool can_attack(const queen& other) const {
        auto p1 = this->coord();
        auto p2 = other.coord();

        if (p1.first == p2.first && p1.second == p2.second) {
            throw std::domain_error("Las reinas no pueden estar en la misma casilla.");
        }

        // Misma fila o misma columna
        if (p1.first == p2.first || p1.second == p2.second) {
            return true;
        }

        // Misma diagonal
        if (std::abs(p1.first - p2.first) == std::abs(p1.second - p2.second)) {
            return true;
        }

        return false;
    }
};

} // namespace queen_attack

// Función principal para probar el código directamente
int main() {
    try {
        queen_attack::queen white({2, 2});
        queen_attack::queen black({0, 4});
        
        if (white.can_attack(black)) {
            std::cout << "Las reinas se pueden atacar." << std::endl;
        } else {
            std::cout << "Las reinas NO se pueden atacar." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
