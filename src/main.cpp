#include <iostream>
#include <memory>
#include "Libro.h"
#include "Biblioteca.h"
#include "Vehiculo.h"
#include "SistemaAlquiler.h"
#include "Producto.h"
#include "CarritoCompras.h"
#include "Usuario.h"

int main() {
    std::cout << "=== PRUEBA SISTEMA DE BIBLIOTECA ===\n";
    Biblioteca miBiblioteca;
    miBiblioteca.agregarLibro(Libro("Clean Code", "Robert C. Martin", "978-0132350884"));
    miBiblioteca.mostrarLibrosDisponibles();

    std::cout << "\n=== PRUEBA SISTEMA DE ALQUILER DE VEHÍCULOS ===\n";
    SistemaAlquiler sistemaAlquiler;
    sistemaAlquiler.registrarVehiculo(std::make_shared<Auto>("Chevrolet", "Sail", "ABC-123", 5));
    sistemaAlquiler.mostrarVehiculosDisponibles();

    std::cout << "\n=== PRUEBA SISTEMA DE CARRITO DE COMPRAS ===\n";
    Producto p1("Laptop Gamer", 1200.0, 5);
    Producto p2("Mouse Inalámbrico", 25.0, 20);

    CarritoCompras carrito;
    carrito.agregarProducto(p1, 1);
    carrito.agregarProducto(p2, 2);
    carrito.mostrarCarrito();

    Usuario usuario("Samuel");
    usuario.agregarAlHistorial(carrito);
    usuario.mostrarHistorial();

    return 0;
}

