#include <iostream>
#include <memory>
#include "Libro.h"
#include "Biblioteca.h"
#include "Vehiculo.h"
#include "SistemaAlquiler.h"

int main() {
    std::cout << "=== PRUEBA SISTEMA DE BIBLIOTECA ===\n";
    Biblioteca miBiblioteca;
    miBiblioteca.agregarLibro(Libro("Clean Code", "Robert C. Martin", "978-0132350884"));
    miBiblioteca.mostrarLibrosDisponibles();

    std::cout << "\n=== PRUEBA SISTEMA DE ALQUILER DE VEHÍCULOS ===\n";
    SistemaAlquiler sistemaAlquiler;

    // Registrar autos y bicicletas usando polimorfismo y smart pointers
    sistemaAlquiler.registrarVehiculo(std::make_shared<Auto>("Chevrolet", "Sail", "ABC-123", 5));
    sistemaAlquiler.registrarVehiculo(std::make_shared<Bicicleta>("Giant", "Ruta X", "BIKE-01", "ruta"));

    // Mostrar disponibles
    sistemaAlquiler.mostrarVehiculosDisponibles();

    // Alquilar un vehículo
    std::cout << "\nAlquilando auto ABC-123...\n";
    sistemaAlquiler.alquilarVehiculo("ABC-123");

    // Mostrar disponibles después del alquiler
    sistemaAlquiler.mostrarVehiculosDisponibles();

    // Devolver el vehículo
    std::cout << "\nDevolviendo auto ABC-123...\n";
    sistemaAlquiler.devolverVehiculo("ABC-123");

    sistemaAlquiler.mostrarVehiculosDisponibles();

    return 0;
}
