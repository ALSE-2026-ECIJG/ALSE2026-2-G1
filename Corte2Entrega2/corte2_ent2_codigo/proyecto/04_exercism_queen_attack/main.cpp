#include <iostream>
#include "queen_attack.h"

using queen_attack::chess_board;

void show(const std::string& label, const chess_board& board) {
    std::cout << label << " -> can_attack() = "
              << (board.can_attack() ? "true" : "false") << "\n";
}

int main() {
    show("Reinas que NO se atacan", chess_board{{2, 4}, {6, 6}});
    show("Reinas en la misma fila", chess_board{{2, 4}, {2, 6}});
    show("Reinas en la misma columna", chess_board{{4, 5}, {2, 5}});
    show("Reinas en diagonal", chess_board{{2, 2}, {0, 4}});

    try {
        chess_board invalido{{8, 4}, {0, 3}};
    } catch (const std::domain_error& e) {
        std::cout << "Error esperado al salirse del tablero: " << e.what() << "\n";
    }

    try {
        chess_board mismaCasilla{{3, 7}, {3, 7}};
    } catch (const std::domain_error& e) {
        std::cout << "Error esperado por casillas iguales: " << e.what() << "\n";
    }

    return 0;
}
