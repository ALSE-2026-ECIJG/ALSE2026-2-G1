#include <iostream>
#include "Biblioteca.h"

int main() {
    Biblioteca biblioteca;

    biblioteca.agregarLibro(Libro("Cien anos de soledad", "Gabriel Garcia Marquez", "111"));
    biblioteca.agregarLibro(Libro("El coronel no tiene quien le escriba", "Gabriel Garcia Marquez", "222"));
    biblioteca.agregarLibro(Libro("Don Quijote", "Miguel de Cervantes", "333"));

    biblioteca.mostrarDisponibles();

    std::cout << "\nPrestando el libro 111..." << std::endl;
    biblioteca.prestarLibro("111");
    biblioteca.mostrarDisponibles();

    std::cout << "\nBuscando por autor 'Cervantes':" << std::endl;
    for (const Libro& libro : biblioteca.buscarPorAutor("Cervantes")) {
        libro.mostrar();
    }

    std::cout << "\nEliminando el libro 222..." << std::endl;
    biblioteca.eliminarLibro("222");
    biblioteca.mostrarDisponibles();

    return 0;
}
