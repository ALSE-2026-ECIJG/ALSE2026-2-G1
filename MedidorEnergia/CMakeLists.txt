cmake_minimum_required(VERSION 3.10)
project(MedidorEnergia VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Carpeta donde están los archivos .h
include_directories(${PROJECT_SOURCE_DIR}/include)

# Ejecutable principal
add_executable(medidor
    src/main.cpp
    src/MedidorEnergia.cpp
)

# Objetivo opcional para generar la documentación: make docs
find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    add_custom_target(docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_SOURCE_DIR}/Doxyfile
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        COMMENT "Generando documentacion con Doxygen"
    )
endif()
