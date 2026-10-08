#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

class Usuario {
protected:
    std::string nombre;
    int id;
    int limitePrestamos;
    std::vector<std::string> prestamosActivos;

public:
    Usuario(const std::string& nombre, int id, int limitePrestamos);
    virtual ~Usuario() = default;

    std::string getNombre() const;
    int getId() const;
    int getLimitePrestamos() const;
    int getPrestamosActivos() const;

    bool puedePrestar() const;
    void agregarPrestamo(const std::string& isbn);
    void devolverPrestamo(const std::string& isbn);

    virtual std::string getRol() const = 0;
    virtual void mostrarInfo() const;
};

class Estudiante : public Usuario {
public:
    Estudiante(const std::string& nombre, int id);
    std::string getRol() const override;
};

class Profesor : public Usuario {
public:
    Profesor(const std::string& nombre, int id);
    std::string getRol() const override;
};

#endif // USUARIO_H
