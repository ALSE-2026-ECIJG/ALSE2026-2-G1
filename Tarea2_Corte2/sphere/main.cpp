#include <iostream>
#include "sphere.h"

int main() {
    Sphere miEsfera(0.0, 0.0, 0.0, 5.0);
    std::cout << "Volumen de la esfera: " << miEsfera.getVolume() << std::endl;
    std::cout << "Area superficial: " << miEsfera.getSurfaceArea() << std::endl;
    return 0;
}

