/**
 * @file MedidorEnergia.cpp
 * @brief Implementación de la clase MedidorEnergia.
 * @author Santiago Cuevas M
 */

#include "MedidorEnergia.h"

#include <numeric>
#include <stdexcept>

MedidorEnergia::MedidorEnergia(const std::string& serie)
    : serie(serie), lecturaActual(0.0f) {
    if (serie.empty()) {
        throw std::invalid_argument("La serie no puede estar vacia.");
    }
}

void MedidorEnergia::registrarLectura(float valor) {
    if (valor < 0.0f) {
        throw std::invalid_argument("La lectura no puede ser negativa.");
    }
    lecturaActual = valor;
    historial.push_back(valor);
}

float MedidorEnergia::calcularConsumoTotal() const {
    return std::accumulate(historial.begin(), historial.end(), 0.0f);
}

float MedidorEnergia::promedioDiario() const {
    if (historial.empty()) {
        return 0.0f;
    }
    return calcularConsumoTotal() / static_cast<float>(historial.size());
}

std::string MedidorEnergia::getSerie() const {
    return serie;
}

float MedidorEnergia::getLecturaActual() const {
    return lecturaActual;
}

std::size_t MedidorEnergia::cantidadLecturas() const {
    return historial.size();
}
