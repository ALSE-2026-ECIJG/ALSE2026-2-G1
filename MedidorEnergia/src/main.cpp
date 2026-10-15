/**
 * @file main.cpp
 * @brief Programa principal: simula varios medidores de energía.
 * @author Santiago Cuevas M
 */

#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

#include "MedidorEnergia.h"

int main() {
    // Contenedor de la STL que almacena los objetos.
    std::vector<MedidorEnergia> medidores;

    // Dos objetos creados directamente (requisito: al menos dos).
    medidores.emplace_back("MED-001");
    medidores.emplace_back("MED-002");

    // Simulación: lecturas diarias de ejemplo para el primer medidor.
    for (float v : {12.5f, 10.0f, 15.2f}) {
        medidores[0].registrarLectura(v);
    }

    // Se piden datos al usuario con cin.
    int dias = 0;
    std::cout << "=== Simulador de medidores de energia ===\n";
    std::cout << "Cuantos dias de lecturas desea registrar en MED-002? ";
    while (!(std::cin >> dias) || dias <= 0) {
        std::cout << "Valor invalido. Ingrese un entero positivo: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 1; i <= dias; ++i) {
        float valor = 0.0f;
        bool valido = false;
        while (!valido) {
            std::cout << "Dia " << i << " - consumo en kWh: ";
            if (!(std::cin >> valor)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Entrada no numerica.\n";
                continue;
            }
            try {
                medidores[1].registrarLectura(valor);
                valido = true;
            } catch (const std::invalid_argument& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }
    }

    // Resultados claros con cout.
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n=== Resultados ===\n";
    for (const MedidorEnergia& m : medidores) {
        std::cout << "Medidor " << m.getSerie() << "\n"
                  << "  Lecturas registradas: " << m.cantidadLecturas() << "\n"
                  << "  Ultima lectura:       " << m.getLecturaActual() << " kWh\n"
                  << "  Consumo total:        " << m.calcularConsumoTotal() << " kWh\n"
                  << "  Promedio diario:      " << m.promedioDiario() << " kWh\n\n";
    }

    return 0;
}
