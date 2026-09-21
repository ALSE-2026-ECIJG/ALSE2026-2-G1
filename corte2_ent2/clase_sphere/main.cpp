#include <iostream>
#include <iomanip>
#include "sphere.h"

int main() {
    std::cout << "=== Clase Sphere ===\n" << std::endl;

    std::cout << std::fixed << std::setprecision(4);

    Sphere s1(3.0);
    std::cout << "Sphere con radio 3.0:" << std::endl;
    std::cout << "  Radio:            " << s1.getRadius() << std::endl;
    std::cout << "  Volumen:          " << s1.getVolume() << std::endl;
    std::cout << "  Area superficial: " << s1.getSurfaceArea() << std::endl;
    std::cout << std::endl;

    Sphere s2;
    std::cout << "Sphere por defecto (radio 1.0):" << std::endl;
    std::cout << "  Radio:            " << s2.getRadius() << std::endl;
    std::cout << "  Volumen:          " << s2.getVolume() << std::endl;
    std::cout << "  Area superficial: " << s2.getSurfaceArea() << std::endl;
    std::cout << std::endl;

    Sphere s3(5.0);
    s3.setRadius(2.0);
    std::cout << "Sphere con radio modificado a 2.0:" << std::endl;
    std::cout << "  Radio:            " << s3.getRadius() << std::endl;
    std::cout << "  Volumen:          " << s3.getVolume() << std::endl;
    std::cout << "  Area superficial: " << s3.getSurfaceArea() << std::endl;
    std::cout << std::endl;

    std::cout << "Sphere con radio invalido (-4.0), usa 1.0:" << std::endl;
    Sphere s4(-4.0);
    std::cout << "  Radio:            " << s4.getRadius() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Fin de las pruebas ===" << std::endl;
    return 0;
}
