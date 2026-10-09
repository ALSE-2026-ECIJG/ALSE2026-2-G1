#include <iostream>
#include <memory>
#include "Vehiculo.h"
#include "Auto.h"
#include "Bicicleta.h"
#include "SistemaAlquiler.h"

int main() {
    SistemaAlquiler sistema;

    // Registrar vehiculos (Auto y Bicicleta via shared_ptr)
    sistema.registrarVehiculo(std::make_shared<Auto>(
        "Toyota", "Corolla", "ABC-123", 5));
    sistema.registrarVehiculo(std::make_shared<Auto>(
        "Mazda", "CX-5", "XYZ-789", 7));
    sistema.registrarVehiculo(std::make_shared<Bicicleta>(
        "Trek", "Marlin 5", "BICI-001", "montaña"));
    sistema.registrarVehiculo(std::make_shared<Bicicleta>(
        "Giant", "Escape 3", "BICI-002", "urbana"));

    std::cout << "\n=== Todos los vehiculos ===\n";
    sistema.mostrarTodos();

    std::cout << "\n=== Alquilar ABC-123 y BICI-001 ===\n";
    sistema.alquilarVehiculo("ABC-123");
    sistema.alquilarVehiculo("BICI-001");

    std::cout << "\n=== Intentar alquilar ABC-123 de nuevo ===\n";
    sistema.alquilarVehiculo("ABC-123");

    std::cout << "\n=== Intentar alquilar placa inexistente ===\n";
    sistema.alquilarVehiculo("NOEXISTE");

    std::cout << "\n=== Vehiculos disponibles ===\n";
    sistema.mostrarDisponibles();

    std::cout << "\n=== Devolver ABC-123 ===\n";
    sistema.devolverVehiculo("ABC-123");

    std::cout << "\n=== Intentar devolver un vehiculo no alquilado ===\n";
    sistema.devolverVehiculo("XYZ-789");

    std::cout << "\n=== Estado final ===\n";
    sistema.mostrarTodos();

    std::cout << "\nTotal vehiculos registrados: "
              << sistema.totalVehiculos() << "\n";

    return 0;
}
