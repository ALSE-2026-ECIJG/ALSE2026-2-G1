#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>

class Queen {
private:
    int row, col;

    static void checkBounds(int r, int c) {
        if (r < 0 || r > 7 || c < 0 || c > 7) {
            throw std::domain_error("Queen position must be on the board (0..7)");
        }
    }

public:
    Queen(int r, int c) : row(r), col(c) {
        checkBounds(r, c);
    }

    int getRow() const { return row; }
    int getCol() const { return col; }

    bool canAttack(const Queen& other) const {
        if (row == other.row) return true;
        if (col == other.col) return true;
        if (std::abs(row - other.row) == std::abs(col - other.col)) return true;
        return false;
    }
};

void testAttack(const std::string& name, int r1, int c1, int r2, int c2) {
    Queen q1(r1, c1);
    Queen q2(r2, c2);
    std::cout << name << ": "
              << (q1.canAttack(q2) ? "SI se atacan" : "NO se atacan")
              << std::endl;
}

int main() {
    std::cout << "=== Exercism: Queen Attack ===\n" << std::endl;

    testAttack("Misma fila      (0,0) y (0,7)", 0, 0, 0, 7);
    testAttack("Misma columna   (0,0) y (7,0)", 0, 0, 7, 0);
    testAttack("Diagonal asc    (0,0) y (7,7)", 0, 0, 7, 7);
    testAttack("Diagonal desc   (0,7) y (7,0)", 0, 7, 7, 0);
    testAttack("Ejemplo PDF c5 y f2", 2, 3, 5, 6);
    testAttack("Sin ataque      (0,0) y (1,2)", 0, 0, 1, 2);
    testAttack("Sin ataque      (2,3) y (4,6)", 2, 3, 4, 6);
    testAttack("Fila 7          (7,0) y (7,5)", 7, 0, 7, 5);
    testAttack("Columna 3       (0,3) y (5,3)", 0, 3, 5, 3);

    std::cout << "\nPrueba de posiciones invalidas:" << std::endl;
    try {
        Queen bad(-1, 0);
        std::cout << "ERROR: no se lanzo excepcion" << std::endl;
    } catch (const std::domain_error& e) {
        std::cout << "Posicion (-1, 0) -> excepcion: " << e.what() << std::endl;
    }

    try {
        Queen bad(0, 8);
        std::cout << "ERROR: no se lanzo excepcion" << std::endl;
    } catch (const std::domain_error& e) {
        std::cout << "Posicion (0, 8) -> excepcion: " << e.what() << std::endl;
    }

    std::cout << "\n=== Fin de las pruebas ===" << std::endl;
    return 0;
}
