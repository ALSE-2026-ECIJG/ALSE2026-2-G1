#ifndef CLOCK_H
#define CLOCK_H

#include <string>

/**
 * @brief Clase que representa un reloj en formato de 24 horas.
 * Gestiona horas y minutos sin fecha, con soporte para suma, resta y comparación.
 */
class Clock {
private:
    int totalMinutes; ///< Total de minutos transcurridos desde las 00:00

    /**
     * @brief Normaliza el tiempo para que siempre esté en el rango [0, 1439].
     * @param minutes Minutos a normalizar.
     */
    void normalize(int minutes);

public:
    /**
     * @brief Constructor del reloj.
     * @param hour Hora inicial (0-23).
     * @param minute Minuto inicial (0-59).
     */
    Clock(int hour, int minute);

    /**
     * @brief Añade minutos al reloj.
     * @param minutes Minutos a añadir.
     * @return Nueva instancia de Clock con el tiempo modificado.
     */
    Clock add(int minutes) const;

    /**
     * @brief Resta minutos al reloj.
     * @param minutes Minutos a restar.
     * @return Nueva instancia de Clock con el tiempo modificado.
     */
    Clock subtract(int minutes) const;

    /**
     * @brief Convierte el reloj a formato de cadena "HH:MM".
     * @return Cadena con la hora formateada.
     */
    std::string toString() const;

    /**
     * @brief Sobrecarga del operador de igualdad.
     * Dos relojes son iguales si representan la misma hora.
     */
    bool operator==(const Clock& other) const;

    /**
     * @brief Sobrecarga del operador de desigualdad.
     */
    bool operator!=(const Clock& other) const;
};

#endif // CLOCK_H
