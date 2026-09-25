#include "sphere.h"
#include <cmath>

Sphere::Sphere(double r) : radius(r) {}

double Sphere::getRadius() const {
    return radius;
}

double Sphere::getVolume() const {
    return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
}

double Sphere::getSurfaceArea() const {
    return 4.0 * M_PI * std::pow(radius, 2);
}
