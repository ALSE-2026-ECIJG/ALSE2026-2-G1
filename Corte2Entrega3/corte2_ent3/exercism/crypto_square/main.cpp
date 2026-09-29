#include <iostream>
#include "crypto_square.h"

int main() {
    crypto_square::cipher c1("If man was meant to stay on the ground, god would have given us roots.");
    std::cout << "Texto: If man was meant to stay on the ground, god would have given us roots." << std::endl;
    std::cout << "Cifrado: \"" << c1.normalized_cipher_text() << "\"" << std::endl << std::endl;

    crypto_square::cipher c2("Never vex thine heart with idle woes");
    std::cout << "Texto: Never vex thine heart with idle woes" << std::endl;
    std::cout << "Cifrado: \"" << c2.normalized_cipher_text() << "\"" << std::endl;

    return 0;
}
