#include <iostream>
#include "SistemaAlquiler.h"
#include "Auto.h"
#include "Bicicleta.h"

int main() {
    SistemaAlquiler sistema;

    sistema.registrarVehiculo(new Auto("Toyota", "Corolla", "ABC123", 5));
    sistema.registrarVehiculo(new Auto("Renault", "Logan", "XYZ789", 5));
    sistema.registrarVehiculo(new Bicicleta("Specialized", "Rockhopper", "BIC001", "montana"));
    sistema.registrarVehiculo(new Bicicleta("Trek", "Domane", "BIC002", "ruta"));

    sistema.mostrarDisponibles();

    std::cout << "\nAlquilando ABC123..." << std::endl;
    sistema.alquilarVehiculo("ABC123");
    sistema.mostrarDisponibles();

    std::cout << "\nIntentando alquilar ABC123 otra vez..." << std::endl;
    if (!sistema.alquilarVehiculo("ABC123")) {
        std::cout << "No se pudo: ya esta alquilado." << std::endl;
    }

    std::cout << "\nDevolviendo ABC123..." << std::endl;
    sistema.devolverVehiculo("ABC123");
    sistema.mostrarDisponibles();

    return 0;
}
