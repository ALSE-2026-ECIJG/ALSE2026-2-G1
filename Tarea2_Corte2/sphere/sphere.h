#ifndef SPHERE_H
#define SPHERE_H

class Sphere {
private:
    double x, y, z;
    double radius;

public:
    Sphere(double x, double y, double z, double r);
    double getVolume() const;
    double getSurfaceArea() const;
};

#endif
