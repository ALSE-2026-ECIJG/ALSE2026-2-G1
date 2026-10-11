#include "Usuario.h"
#include <iostream>

Usuario::Usuario(const std::string& nombre) : nombre(nombre) {}

const std::string& Usuario::getNombre() const { return nombre; }

void Usuario::agregarCompra(const CarritoCompras& compra) {
    historial.push_back(compra);
}

void Usuario::mostrarHistorial() const {
    std::cout << "Historial de " << nombre << ":\n";
    int n = 1;
    for (const auto& compra : historial) {
        std::cout << "Compra #" << n++ << "\n";
        compra.mostrar();
    }
}
