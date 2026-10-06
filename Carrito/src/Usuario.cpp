#include "Usuario.h"
#include <iostream>
#include <iomanip>

Usuario::Usuario(const std::string& nombre) : nombre(nombre) {}

std::string Usuario::getNombre() const { return nombre; }

void Usuario::agregarCompra(double total) {
    historial.push_back(total);
}

void Usuario::mostrarHistorial() const {
    std::cout << "--- Historial de " << nombre << " ---" << std::endl;
    if (historial.empty()) {
        std::cout << "Sin compras." << std::endl;
        return;
    }
    for (size_t i = 0; i < historial.size(); i++) {
        std::cout << "Compra #" << (i + 1) << ": $"
                  << std::fixed << std::setprecision(2)
                  << historial[i] << std::endl;
    }
}
