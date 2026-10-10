#include <iostream>
#include "Libro.h"
#include "Biblioteca.h"

int main() {
    Biblioteca miBiblioteca;

    // Agregar libros de prueba
    miBiblioteca.agregarLibro(Libro("Cien años de soledad", "Gabriel García Márquez", "978-0307474728"));
    miBiblioteca.agregarLibro(Libro("Don Quijote de la Mancha", "Miguel de Cervantes", "978-8424933271"));
    miBiblioteca.agregarLibro(Libro("El principito", "Antoine de Saint-Exupéry", "978-0156012195"));

    // Mostrar disponibles
    miBiblioteca.mostrarLibrosDisponibles();

    // Buscar por autor
    std::cout << "\nBuscando libros de Gabriel García Márquez:\n";
    miBiblioteca.buscarPorAutor("Gabriel García Márquez");

    // Eliminar un libro
    std::cout << "\nEliminando libro con ISBN 978-0156012195...\n";
    miBiblioteca.eliminarLibro("978-0156012195");

    // Mostrar disponibles de nuevo
    miBiblioteca.mostrarLibrosDisponibles();

    return 0;
}
