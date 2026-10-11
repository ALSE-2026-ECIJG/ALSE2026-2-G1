#include <iostream>
#include <limits>
#include <string>
#include "SistemaAlquiler.h"
#include "Auto.h"
#include "Bicicleta.h"

/** @brief Muestra un texto y lee una línea completa (permite espacios). */
std::string leerTexto(const std::string& mensaje) {
    std::string texto;
    std::cout << mensaje;
    std::getline(std::cin, texto);
    return texto;
}

/** @brief Lee un número entero desde el teclado (repite si escriben otra cosa). */
int leerEntero() {
    int valor;
    while (!(std::cin >> valor)) {
        if (std::cin.eof()) return 0;  // se acabó la entrada
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Escribe un numero valido: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}

int main() {
    SistemaAlquiler sistema;

    // Vehículos iniciales (el usuario puede registrar más)
    sistema.registrarVehiculo(new Auto("Toyota", "Corolla", "ABC123", 5));
    sistema.registrarVehiculo(new Auto("Mazda", "3", "XYZ789", 5));
    sistema.registrarVehiculo(new Bicicleta("GW", "Zaxon", "BIC001", "montana"));

    int opcion = -1;
    while (opcion != 0) {
        std::cout << "\n===== ALQUILER DE VEHICULOS =====\n"
                  << "1. Registrar auto\n"
                  << "2. Registrar bicicleta\n"
                  << "3. Alquilar vehiculo\n"
                  << "4. Devolver vehiculo\n"
                  << "5. Mostrar vehiculos disponibles\n"
                  << "0. Salir\n"
                  << "Opcion: ";
        opcion = leerEntero();

        if (opcion == 1) {
            std::string marca = leerTexto("Marca: ");
            std::string modelo = leerTexto("Modelo: ");
            std::string placa = leerTexto("Placa: ");
            std::cout << "Capacidad de pasajeros: ";
            int pasajeros = leerEntero();
            if (marca.empty() || modelo.empty() || placa.empty() || pasajeros <= 0) {
                std::cout << "Datos invalidos.\n";
            } else if (sistema.registrarVehiculo(new Auto(marca, modelo, placa, pasajeros))) {
                std::cout << "Auto registrado.\n";
            } else {
                std::cout << "Ya existe un vehiculo con esa placa.\n";
            }

        } else if (opcion == 2) {
            std::string marca = leerTexto("Marca: ");
            std::string modelo = leerTexto("Modelo: ");
            std::string placa = leerTexto("Placa: ");
            std::string tipo = leerTexto("Tipo (montana, ruta, urbana): ");
            if (marca.empty() || modelo.empty() || placa.empty() || tipo.empty()) {
                std::cout << "Datos invalidos.\n";
            } else if (sistema.registrarVehiculo(new Bicicleta(marca, modelo, placa, tipo))) {
                std::cout << "Bicicleta registrada.\n";
            } else {
                std::cout << "Ya existe un vehiculo con esa placa.\n";
            }

        } else if (opcion == 3) {
            std::string placa = leerTexto("Placa del vehiculo a alquilar: ");
            if (sistema.alquilar(placa)) {
                std::cout << "Vehiculo alquilado.\n";
            } else {
                std::cout << "No se pudo alquilar (no existe o ya esta alquilado).\n";
            }

        } else if (opcion == 4) {
            std::string placa = leerTexto("Placa del vehiculo a devolver: ");
            if (sistema.devolver(placa)) {
                std::cout << "Vehiculo devuelto.\n";
            } else {
                std::cout << "No se pudo devolver (no existe o no estaba alquilado).\n";
            }

        } else if (opcion == 5) {
            std::cout << "\n--- Vehiculos disponibles ---\n";
            sistema.mostrarDisponibles();

        } else if (opcion != 0) {
            std::cout << "Opcion no valida.\n";
        }
    }

    std::cout << "Hasta luego!\n";
    return 0;
}
