#pragma once

#include <cmath>

namespace geometric {

class Sphere {
private:
    double radius;
    double center_x, center_y, center_z;

public:
    Sphere(double r = 1.0, double x = 0.0, double y = 0.0, double z = 0.0) 
        : radius(r), center_x(x), center_y(y), center_z(z) {}

    double get_radius() const { return radius; }
    
    double get_volume() const {
        return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
    }

    double get_surface_area() const {
        return 4.0 * M_PI * std::pow(radius, 2);
    }
};

} // namespace geometric

