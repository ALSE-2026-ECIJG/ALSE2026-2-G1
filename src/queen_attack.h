#pragma once

#include <utility>
#include <stdexcept>
#include <cmath>

namespace queen_attack {

class chess_board {
private:
    std::pair<int, int> white_queen;
    std::pair<int, int> black_queen;

public:
    chess_board(std::pair<int, int> white, std::pair<int, int> black) 
        : white_queen(white), black_queen(black) {
        if (white.first == black.first && white.second == black.second) {
            throw std::domain_error("The queens cannot occupy the same position.");
        }
        if (white.first < 0 || white.first > 7 || white.second < 0 || white.second > 7 ||
            black.first < 0 || black.first > 7 || black.second < 0 || black.second > 7) {
            throw std::domain_error("Position must be between 0 and 7.");
        }
    }

    std::pair<int, int> white() const {
        return white_queen;
    }

    std::pair<int, int> black() const {
        return black_queen;
    }

    bool can_attack() const {
        // Misma fila o misma columna
        if (white_queen.first == black_queen.first || white_queen.second == black_queen.second) {
            return true;
        }
        // Misma diagonal (la diferencia absoluta en X es igual a la diferencia absoluta en Y)
        if (std::abs(white_queen.first - black_queen.first) == std::abs(white_queen.second - black_queen.second)) {
            return true;
        }
        return false;
    }
};

} // namespace queen_attack

