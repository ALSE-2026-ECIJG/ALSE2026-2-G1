# MedidorEnergia

Proyecto en C++17 que simula medidores de energía eléctrica. Cada medidor
tiene un número de serie, una lectura actual y un historial de lecturas
(`std::vector<float>`). Permite registrar lecturas, calcular el consumo
total y el promedio diario.

Autor: Santiago Cuevas M

## Estructura

```
MedidorEnergia/
├── CMakeLists.txt
├── Doxyfile
├── include/MedidorEnergia.h
├── src/MedidorEnergia.cpp
├── src/main.cpp
└── docs/            (documentación HTML generada por Doxygen)
```

## Compilación

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Ejecución

```bash
./medidor          # Linux / macOS
.\Debug\medidor.exe  # Windows (Visual Studio)
```

## Ejemplo de ejecución

```
=== Simulador de medidores de energia ===
Cuantos dias de lecturas desea registrar en MED-002? 2
Dia 1 - consumo en kWh: 8.5
Dia 2 - consumo en kWh: 11.5

=== Resultados ===
Medidor MED-001
  Lecturas registradas: 3
  Ultima lectura:       15.20 kWh
  Consumo total:        37.70 kWh
  Promedio diario:      12.57 kWh

Medidor MED-002
  Lecturas registradas: 2
  Ultima lectura:       11.50 kWh
  Consumo total:        20.00 kWh
  Promedio diario:      10.00 kWh
```

## Documentación

Desde la carpeta del proyecto: `doxygen Doxyfile`. Abrir `docs/index.html`.
