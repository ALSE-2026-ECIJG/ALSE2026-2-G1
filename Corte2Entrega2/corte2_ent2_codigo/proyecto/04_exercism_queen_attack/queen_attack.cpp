#include "queen_attack.h"
#include <stdexcept>
#include <cmath>

namespace queen_attack {

chess_board::chess_board()
    : white_queen_{0, 3}, black_queen_{7, 3} {}

chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black)
    : white_queen_{white}, black_queen_{black} {

    if (white.first < 0 || white.first >= 8 || white.second < 0 || white.second >= 8 ||
        black.first < 0 || black.first >= 8 || black.second < 0 || black.second >= 8) {
        throw std::domain_error("Queen position must be on the board");
    }

    if (white == black) {
        throw std::domain_error("Queens cannot share the same position");
    }
}

std::pair<int, int> chess_board::white() const {
    return white_queen_;
}

std::pair<int, int> chess_board::black() const {
    return black_queen_;
}

bool chess_board::can_attack() const {
    if (white_queen_.first == black_queen_.first) {
        return true;
    }

    if (white_queen_.second == black_queen_.second) {
        return true;
    }

    if (std::abs(white_queen_.first - black_queen_.first) ==
        std::abs(white_queen_.second - black_queen_.second)) {
        return true;
    }

    return false;
}

}
