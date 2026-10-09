#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    std::string placa;
    bool disponible;

public:
    Vehiculo(const std::string& marca,
             const std::string& modelo,
             const std::string& placa);
    virtual ~Vehiculo() = default;

    std::string getMarca() const;
    std::string getModelo() const;
    std::string getPlaca() const;
    bool isDisponible() const;

    void setDisponible(bool estado);

    // Metodo virtual puro: cada tipo de vehiculo lo personaliza
    virtual void mostrarInformacion() const = 0;

    // Utilidad: tipo de vehiculo como string (para impresion)
    virtual std::string getTipo() const = 0;
};

#endif // VEHICULO_H
