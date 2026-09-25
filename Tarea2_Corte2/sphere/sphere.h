#ifndef SPHERE_H
#define SPHERE_H

class Sphere {
private:
    double radius;
public:
    Sphere(double r);
    double getRadius() const;
    double getVolume() const;
    double getSurfaceArea() const;
};

#endif
