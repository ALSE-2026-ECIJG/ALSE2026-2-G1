#ifndef __CUBE_H__
#define __CUBE_H__
#include "shape3d.h"
#include <iostream>
/**
 * @class Cube
 * @brief Representa un cubo en 3D, derivado de Shape3D.
 *
 * Proporciona métodos para calcular el volumen y el área superficial,
 * así como para manipular la longitud de sus lados.
 */
class Cube : public Shape3D {
private:
    double length;
public:
     /**
      * @brief Constructor que inicializa el cubo con una longitud dada.
      * @param len Longitud del lado del cubo.
      */
    Cube(double len);
     /**
      * @brief Constructor por defecto. Inicializa el cubo con longitud cero.
      */
    Cube();
     /**
      * @brief Calcula el volumen del cubo.
      * @return Volumen del cubo.
      */
    double getVolume() const override;
     /**
      * @brief Calcula el área superficial del cubo.
      * @return Área superficial del cubo.
      */
    double getSurfaceArea() const override;
     /**
      * @brief Establece la longitud del lado del cubo.
      * @param len Nueva longitud del lado.
      */
    void setLength(double len);
     /**
      * @brief Obtiene la longitud del lado del cubo.
      * @return Longitud del lado.
      */
    double getLength() const;
     /**
      * @brief Destructor de la clase Cube.
      */
    ~Cube() override;
};
#endif // __CUBE_H__