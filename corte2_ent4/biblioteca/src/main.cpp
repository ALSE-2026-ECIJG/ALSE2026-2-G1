#include <iostream>
#include "Libro.h"
#include "Usuario.h"
#include "Biblioteca.h"

int main() {
    Biblioteca bib;

    bib.agregarLibro(Libro("Cien anios de soledad", "Gabriel Garcia Marquez", "ISBN-001"));
    bib.agregarLibro(Libro("El Quijote",            "Miguel de Cervantes",  "ISBN-002"));
    bib.agregarLibro(Libro("La ciudad y los perros","Mario Vargas Llosa",   "ISBN-003"));
    bib.agregarLibro(Libro("Pedro Paramo",          "Juan Rulfo",           "ISBN-004"));

    std::cout << "\n=== Catalogo inicial ===\n";
    bib.mostrarCatalogo();

    std::cout << "\n=== Buscar por autor 'Garcia' ===\n";
    for (const auto& l : bib.buscarPorAutor("Garcia")) l.mostrarInfo();

    std::cout << "\n=== Buscar por titulo 'Quijote' ===\n";
    for (const auto& l : bib.buscarPorTitulo("Quijote")) l.mostrarInfo();

    Estudiante est("Samuel", 2024001);
    Profesor   prof("Dra. Lopez", 9001);

    est.mostrarInfo();
    prof.mostrarInfo();

    std::cout << "\n=== Prestamos ===\n";
    bib.prestarLibro("ISBN-001", est);
    bib.prestarLibro("ISBN-002", prof);
    bib.prestarLibro("ISBN-002", est);

    std::cout << "\n=== Libros disponibles ===\n";
    for (const auto& l : bib.librosDisponibles()) l.mostrarInfo();

    std::cout << "\n=== Devolucion ===\n";
    bib.devolverLibro("ISBN-001", est);

    std::cout << "\n=== Eliminar ISBN-004 ===\n";
    bib.eliminarLibro("ISBN-004");

    std::cout << "\n=== Catalogo final ===\n";
    bib.mostrarCatalogo();

    return 0;
}
