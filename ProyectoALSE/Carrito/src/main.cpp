#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "Producto.h"
#include "CarritoCompras.h"
#include "Usuario.h"

/** @brief Muestra un texto y lee una línea completa (permite espacios). */
std::string leerTexto(const std::string& mensaje) {
    std::string texto;
    std::cout << mensaje;
    std::getline(std::cin, texto);
    return texto;
}

/** @brief Lee un número entero desde el teclado (repite si escriben otra cosa). */
int leerEntero() {
    int valor;
    while (!(std::cin >> valor)) {
        if (std::cin.eof()) return 0;  // se acabó la entrada
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Escribe un numero valido: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}

/** @brief Lee un número decimal desde el teclado (repite si escriben otra cosa). */
double leerDecimal() {
    double valor;
    while (!(std::cin >> valor)) {
        if (std::cin.eof()) return 0;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Escribe un numero valido: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}

/** @brief Muestra los productos de la tienda con su número, precio y stock. */
void mostrarProductos(const std::vector<Producto*>& inventario) {
    std::cout << "\n--- Productos de la tienda ---\n";
    if (inventario.empty()) {
        std::cout << "(no hay productos)\n";
        return;
    }
    for (size_t i = 0; i < inventario.size(); i++) {
        std::cout << i + 1 << ". " << inventario[i]->getNombre()
                  << " - $" << inventario[i]->getPrecio()
                  << " (stock: " << inventario[i]->getStock() << ")\n";
    }
}

/** @brief Pide al usuario que elija un producto y devuelve su posición (o -1 si no es válido). */
int elegirProducto(const std::vector<Producto*>& inventario) {
    mostrarProductos(inventario);
    if (inventario.empty()) return -1;
    std::cout << "Numero del producto: ";
    int n = leerEntero();
    if (n < 1 || n > (int)inventario.size()) {
        std::cout << "Producto no valido.\n";
        return -1;
    }
    return n - 1;
}

int main() {
    // Productos iniciales (el usuario puede registrar más desde el menú)
    std::vector<Producto*> inventario;
    inventario.push_back(new Producto("Camiseta", 30000, 10));
    inventario.push_back(new Producto("Gorra", 20000, 5));
    inventario.push_back(new Producto("Buso", 80000, 3));
    inventario.push_back(new Producto("Medias", 8000, 20));

    std::string nombre = leerTexto("Tu nombre: ");
    Usuario usuario(nombre);
    CarritoCompras carrito;

    int opcion = -1;
    while (opcion != 0) {
        std::cout << "\n===== TIENDA EN LINEA =====\n"
                  << "1. Ver productos\n"
                  << "2. Agregar producto al carrito\n"
                  << "3. Quitar producto del carrito\n"
                  << "4. Ver carrito\n"
                  << "5. Finalizar compra\n"
                  << "6. Ver historial de compras\n"
                  << "7. Registrar producto nuevo en la tienda\n"
                  << "0. Salir\n"
                  << "Opcion: ";
        opcion = leerEntero();

        if (opcion == 1) {
            mostrarProductos(inventario);

        } else if (opcion == 2) {
            int pos = elegirProducto(inventario);
            if (pos != -1) {
                std::cout << "Cantidad: ";
                int cantidad = leerEntero();
                if (carrito.agregarProducto(inventario[pos], cantidad)) {
                    std::cout << "Agregado al carrito.\n";
                } else {
                    std::cout << "No se pudo agregar (cantidad invalida o stock insuficiente).\n";
                }
            }

        } else if (opcion == 3) {
            int pos = elegirProducto(inventario);
            if (pos != -1) {
                if (carrito.eliminarProducto(inventario[pos]->getNombre())) {
                    std::cout << "Producto quitado del carrito.\n";
                } else {
                    std::cout << "Ese producto no esta en el carrito.\n";
                }
            }

        } else if (opcion == 4) {
            std::cout << "\n--- Tu carrito ---\n";
            carrito.mostrar();

        } else if (opcion == 5) {
            if (carrito.calcularTotal() == 0) {
                std::cout << "El carrito esta vacio.\n";
            } else if (carrito.finalizarCompra()) {
                usuario.agregarCompra(carrito);
                carrito.vaciar();
                std::cout << "Compra realizada. Gracias, " << usuario.getNombre() << "!\n";
            } else {
                std::cout << "No hay stock suficiente para finalizar la compra.\n";
            }

        } else if (opcion == 6) {
            usuario.mostrarHistorial();

        } else if (opcion == 7) {
            std::string nuevo = leerTexto("Nombre del producto: ");
            std::cout << "Precio: ";
            double precio = leerDecimal();
            std::cout << "Stock: ";
            int stock = leerEntero();

            bool repetido = false;
            for (size_t i = 0; i < inventario.size(); i++) {
                if (inventario[i]->getNombre() == nuevo) repetido = true;
            }
            if (nuevo.empty() || precio <= 0 || stock < 0) {
                std::cout << "Datos invalidos.\n";
            } else if (repetido) {
                std::cout << "Ya existe un producto con ese nombre.\n";
            } else {
                inventario.push_back(new Producto(nuevo, precio, stock));
                std::cout << "Producto registrado.\n";
            }

        } else if (opcion != 0) {
            std::cout << "Opcion no valida.\n";
        }
    }

    // Liberar la memoria de los productos
    for (size_t i = 0; i < inventario.size(); i++) {
        delete inventario[i];
    }

    std::cout << "Hasta luego!\n";
    return 0;
}
