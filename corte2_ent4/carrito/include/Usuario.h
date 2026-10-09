#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "CarritoCompras.h"

class Usuario {
private:
    std::string nombre;
    int id;
    CarritoCompras carrito;
    std::vector<double> historialCompras;

public:
    Usuario(const std::string& nombre, int id);

    std::string getNombre() const;
    int getId() const;

    CarritoCompras& getCarrito();
    const CarritoCompras& getCarrito() const;

    void agregarAlCarrito(const Producto& producto, int cantidad);
    void eliminarDelCarrito(const std::string& nombre);

    double finalizarCompra();

    const std::vector<double>& getHistorial() const;
    double totalGastado() const;

    void mostrarHistorial() const;
};

#endif // USUARIO_H
