#ifndef __SPHERE_H__
#define __SPHERE_H__
#include "shape3d.h"

class Sphere : public Shape3D {
private:
    double radius;
public:
    Sphere(double r);
    Sphere();
    double getVolume() const override;
    double getSurfaceArea() const override;
    void setRadius(double r);
    double getRadius() const;
    ~Sphere() override;
};

#endif // __SPHERE_H__
