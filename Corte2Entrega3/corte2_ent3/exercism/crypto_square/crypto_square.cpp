#include "crypto_square.h"
#include <cctype>
#include <cmath>
namespace crypto_square {
cipher::cipher(const std::string& text) : plain_text(text) {}
std::string cipher::normalized_cipher_text() const {
    std::string normalized = "";
    for (char ch : plain_text) {
        if (std::isalnum(static_cast<unsigned char>(ch))) {
            normalized += std::tolower(static_cast<unsigned char>(ch));
        }
    }
    int length = normalized.length();
    if (length == 0) {
        return "";
    }
    int c = std::ceil(std::sqrt(length));
    int r = (c * (c - 1) >= length) ? c - 1 : c;
    std::string result = "";
    for (int col = 0; col < c; ++col) {
        if (col > 0) {
            result += " ";
        }
        for (int row = 0; row < r; ++row) {
            int idx = row * c + col;
            if (idx < length) {
                result += normalized[idx];
            } else {
                result += ' ';
            }
        }
    }
    return result;
}
}
