#include <iostream>
#include "sphere.h"

int main() {
    Sphere s(5.0);
    std::cout << "Radio: " << s.getRadius() << std::endl;
    std::cout << "Volumen: " << s.getVolume() << std::endl;
    std::cout << "Area Superficial: " << s.getSurfaceArea() << std::endl;
    return 0;
}
