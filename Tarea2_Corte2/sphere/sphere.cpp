#include "sphere.h"
#include <cmath>

Sphere::Sphere(double x, double y, double z, double r) : x(x), y(y), z(z), radius(r) {}

double Sphere::getVolume() const {
    return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
}

double Sphere::getSurfaceArea() const {
    return 4.0 * M_PI * std::pow(radius, 2);
}
