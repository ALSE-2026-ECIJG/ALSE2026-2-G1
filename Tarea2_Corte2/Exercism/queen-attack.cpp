#include <iostream>
#include <cmath>
#include <stdexcept>

class Queen {
private:
    int row;
    int col;

public:
    Queen(int r, int c) {
        if (r < 0 || r > 7 || c < 0 || c > 7) {
            throw std::out_of_range("La posición debe estar entre 0 y 7.");
        }
        row = r;
        col = c;
    }

    int getRow() const { return row; }
    int getCol() const { return col; }
};

class QueenAttack {
public:
    static bool canAttack(const Queen& white, const Queen& black) {
        // Validación extra: no pueden estar en la misma casilla exacta
        if (white.getRow() == black.getRow() && white.getCol() == black.getCol()) {
            throw std::domain_error("Las reinas no pueden ocupar la misma posición.");
        }

        // Misma fila
        if (white.getRow() == black.getRow()) return true;

        // Misma columna
        if (white.getCol() == black.getCol()) return true;

        // Misma diagonal (la diferencia absoluta entre filas es igual a la diferencia absoluta entre columnas)
        if (std::abs(white.getRow() - black.getRow()) == std::abs(white.getCol() - black.getCol())) return true;

        return false;
    }
};

// Función principal (main) para probar el ejercicio en la terminal
int main() {
    try {
        // Ejemplo de la imagen: Reina blanca en (3, 2) [c5] y reina negra en (6, 5) [f2]
        Queen whiteQueen(3, 2);
        Queen blackQueen(6, 5);

        bool resultado = QueenAttack::canAttack(whiteQueen, blackQueen);

        std::cout << "¿Se pueden atacar las reinas? " 
                  << (resultado ? "Sí (Esperado: Sí, comparten diagonal[cite: 9])" : "No") 
                  << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
