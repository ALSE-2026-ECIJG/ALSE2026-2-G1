/**
 * @file MedidorEnergia.h
 * @brief Declaración de la clase MedidorEnergia.
 * @author Santiago Cuevas M
 */

#ifndef MEDIDOR_ENERGIA_H
#define MEDIDOR_ENERGIA_H

#include <string>
#include <vector>

/**
 * @class MedidorEnergia
 * @brief Simula un medidor de energía que registra lecturas de consumo.
 *
 * Cada lectura representa el consumo (en kWh) de un día. La clase
 * guarda todas las lecturas en un historial y permite calcular el
 * consumo total y el promedio diario.
 */
class MedidorEnergia {
private:
    std::string serie;           ///< Número de serie del medidor.
    float lecturaActual;         ///< Última lectura registrada (kWh).
    std::vector<float> historial; ///< Todas las lecturas registradas (kWh).

public:
    /**
     * @brief Constructor del medidor.
     * @param serie Número de serie (no puede estar vacío).
     * @throws std::invalid_argument si la serie está vacía.
     */
    explicit MedidorEnergia(const std::string& serie);

    /**
     * @brief Registra una nueva lectura de consumo.
     * @param valor Consumo en kWh (debe ser mayor o igual a 0).
     * @throws std::invalid_argument si el valor es negativo.
     */
    void registrarLectura(float valor);

    /**
     * @brief Calcula el consumo total acumulado.
     * @return Suma de todas las lecturas del historial (kWh).
     */
    float calcularConsumoTotal() const;

    /**
     * @brief Calcula el promedio diario de consumo.
     * @return Consumo total dividido entre el número de lecturas;
     *         0 si todavía no hay lecturas.
     */
    float promedioDiario() const;

    /**
     * @brief Obtiene el número de serie.
     * @return Serie del medidor.
     */
    std::string getSerie() const;

    /**
     * @brief Obtiene la última lectura registrada.
     * @return Última lectura en kWh (0 si no hay lecturas).
     */
    float getLecturaActual() const;

    /**
     * @brief Obtiene la cantidad de lecturas registradas.
     * @return Tamaño del historial.
     */
    std::size_t cantidadLecturas() const;
};

#endif // MEDIDOR_ENERGIA_H
