#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

// Clase base abstracta o general
class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    std::string placa;
    bool disponible;

public:
    Vehiculo(std::string marca, std::string modelo, std::string placa, bool disponible = true);
    virtual ~Vehiculo() = default;

    std::string getMarca() const;
    std::string getModelo() const;
    std::string getPlaca() const;
    bool isDisponible() const;
    void setDisponible(bool disp);

    // Método virtual para personalizar en clases derivadas
    virtual void mostrarInformacion() const = 0;
};

// Clase derivada: Auto
class Auto : public Vehiculo {
private:
    int capacidadPasajeros;

public:
    Auto(std::string marca, std::string modelo, std::string placa, int pasajeros, bool disponible = true);
    void mostrarInformacion() const override;
};

// Clase derivada: Bicicleta
class Bicicleta : public Vehiculo {
private:
    std::string tipo; // montaña, ruta, urbana

public:
    Bicicleta(std::string marca, std::string modelo, std::string placa, std::string tipo, bool disponible = true);
    void mostrarInformacion() const override;
};

#endif // VEHICULO_H
