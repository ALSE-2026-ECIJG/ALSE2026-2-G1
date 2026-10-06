cmake_minimum_required(VERSION 3.10)
project(Carrito)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(carrito
    src/main.cpp
    src/Producto.cpp
    src/ItemCarrito.cpp
    src/CarritoCompras.cpp
    src/Usuario.cpp
)
