#ifndef __SPHERE_H__
#define __SPHERE_H__
#include "shape3d.h"
#include <iostream>

/**
 * @class Sphere
 * @brief Representa una esfera en 3D, derivada de Shape3D.
 *
 * Provee métodos para calcular el volumen y el área superficial a
 * partir del radio, además de getters/setters para manipularlo.
 */
class Sphere : public Shape3D {
private:
    double radius;

public:
    /**
     * @brief Constructor que inicializa la esfera con un radio dado.
     *        Si el radio no es positivo, se usa 1.0 por defecto.
     * @param r Radio de la esfera.
     */
    Sphere(double r);

    /// Constructor por defecto. Inicializa la esfera con radio 1.0.
    Sphere();

    /// Calcula el volumen de la esfera: (4/3) * pi * r^3.
    double getVolume() const override;

    /// Calcula el área superficial de la esfera: 4 * pi * r^2.
    double getSurfaceArea() const override;

    /// Establece un nuevo radio (solo si es positivo).
    void setRadius(double r);

    /// Obtiene el radio actual.
    double getRadius() const;

    /// Destructor de la clase Sphere.
    ~Sphere() override;
};
#endif  // __SPHERE_H__