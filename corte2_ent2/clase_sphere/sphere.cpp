#include "sphere.h"
#include <cmath>
#include <iostream>

Sphere::Sphere(double r) {
    if (r > 0) {
        radius = r;
    } else {
        radius = 1.0;
    }
}

Sphere::Sphere() {
    radius = 1.0;
}

double Sphere::getVolume() const {
    return (4.0 / 3.0) * M_PI * radius * radius * radius;
}

double Sphere::getSurfaceArea() const {
    return 4.0 * M_PI * radius * radius;
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
