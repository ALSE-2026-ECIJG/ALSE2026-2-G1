#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

std::string normalize(const std::string& text) {
    std::string result;
    for (char c : text) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            result += std::tolower(static_cast<unsigned char>(c));
        }
    }
    return result;
}

std::string encode(const std::string& plaintext) {
    std::string norm = normalize(plaintext);
    if (norm.empty()) return "";

    int n = norm.size();
    int c = std::ceil(std::sqrt(n));
    int r = std::ceil(static_cast<double>(n) / c);

    std::vector<std::string> rows(r, std::string(c, ' '));
    for (int i = 0; i < n; ++i) {
        rows[i / c][i % c] = norm[i];
    }

    std::string cipher;
    for (int col = 0; col < c; ++col) {
        for (int row = 0; row < r; ++row) {
            cipher += rows[row][col];
        }
    }

    std::string result;
    for (int i = 0; i < c; ++i) {
        if (i > 0) result += " ";
        result += cipher.substr(i * r, r);
    }
    return result;
}

int main() {
    std::cout << "=== Exercism: Crypto Square ===\n" << std::endl;

    std::cout << "encode(\"\") = \"" << encode("") << "\"" << std::endl;
    std::cout << "encode(\"... --- ...\") = \"" << encode("... --- ...") << "\"" << std::endl;
    std::cout << "encode(\"A\") = \"" << encode("A") << "\"" << std::endl;
    std::cout << "encode(\"  b \") = \"" << encode("  b ") << "\"" << std::endl;
    std::cout << "encode(\"@1,%!\") = \"" << encode("@1,%!") << "\"" << std::endl;
    std::cout << "encode(\"This is fun!\") = \"" << encode("This is fun!") << "\"" << std::endl;
    std::cout << "encode(\"Chill out.\") = \"" << encode("Chill out.") << "\"" << std::endl;
    std::cout << "encode(\"If man was meant to stay on the ground, god would have given us roots.\") = \""
              << encode("If man was meant to stay on the ground, god would have given us roots.") << "\"" << std::endl;

    std::cout << "\n=== Fin de las pruebas ===" << std::endl;
    return 0;
}
