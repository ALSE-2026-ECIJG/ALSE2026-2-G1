#include "crypto_square.h"
#include <cmath>
#include <cctype>
#include <algorithm>

namespace crypto_square {

class cipher {
    std::string text;
public:
    explicit cipher(std::string input) {
        for (char c : input) {
            if (std::isalnum(c)) {
                text += std::tolower(c);
            }
        }
    }

    std::string cipher_text() const {
        if (text.empty()) return "";
        
        int len = text.length();
        int c = std::round(std::sqrt(len));
        int r = c;
        if (c * r < len) {
            if (c < r) c++;
            else r++;
        }
        if (c * r < len) r++;

        std::vector<std::string> rectangle(r, std::string(c, ' '));
        int idx = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (idx < len) {
                    rectangle[i][j] = text[idx++];
                }
            }
        }

        std::string result;
        for (int j = 0; j < c; ++j) {
            for (int i = 0; i < r; ++i) {
                result += rectangle[i][j];
            }
            if (j < c - 1) {
                result += ' ';
            }
        }
        return result;
    }
};

} // crypto_square

