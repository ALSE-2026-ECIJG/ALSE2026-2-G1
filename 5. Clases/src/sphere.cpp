#include "sphere.h"
#include <cmath>

namespace {
constexpr double kPi = 3.14159265358979323846;
}

Sphere::Sphere(double r) {
    if (r > 0) {
        radius = r;
    } else {
        radius = 1.0;  // radio por defecto si el valor es inválido
    }
}

Sphere::Sphere() {
    radius = 1.0;
}

double Sphere::getVolume() const {
    return (4.0 / 3.0) * kPi * std::pow(radius, 3);
}

double Sphere::getSurfaceArea() const {
    return 4 * kPi * radius * radius;
}

void Sphere::setRadius(double r) {
    if (r > 0) {
        radius = r;
    }
}

double Sphere::getRadius() const {
    return radius;
}

Sphere::~Sphere() {
    std::cout << "Sphere destructor called" << std::endl;
}