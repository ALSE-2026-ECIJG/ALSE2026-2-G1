# Corte 2 - Entrega 2

Soluciones a los 5 ejercicios de la entrega (LeetCode 355 y 3484, Exercism
robot-simulator y queen-attack, y la clase Sphere del repositorio de clase).

## Estructura

```
.
├── CMakeLists.txt                     <- raíz: compila TODO con un solo comando  como pedia lo minimo
├── 01_leetcode_design_twitter/
├── 02_leetcode_design_spreadsheet/
├── 03_exercism_robot_simulator/
├── 04_exercism_queen_attack/
└── 05_clase_sphere/
```

Cada carpeta contiene: los header(s), los .cpp de implementación,
un `main.cpp` de demostración y su propio `CMakeLists.txt`.

## Cómo compilar todo con un solo comando :D yey

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

Esto genera 5 ejecutables (uno por ejercicio):

- `01_leetcode_design_twitter/design_twitter`
- `02_leetcode_design_spreadsheet/design_spreadsheet`
- `03_exercism_robot_simulator/robot_simulator`
- `04_exercism_queen_attack/queen_attack`
- `05_clase_sphere/sphere_demo`

## Autores

- Nicolas Huerfano
- santiago Ruda
- Nicolas Lombana
