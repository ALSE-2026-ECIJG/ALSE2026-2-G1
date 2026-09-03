# Explicación de las Decisiones de Implementación

### Pregunta 1 — Tipos
En el ejercicio 1, la suma, resta y multiplicación de dos enteros siempre resultan en otro número entero. Sin embargo, la división de dos enteros puede generar un resultado con parte decimal. Por ello, `dividir()` retorna `double` y utiliza `static_cast<double>` para realizar una división flotante precisa en lugar de una división entera truncada.

### Pregunta 2 — Operadores
En el ejercicio 3, utilicé el operador módulo `%` para verificar si un número es par comprobando si el residuo al dividir entre 2 es cero (`numero % 2 == 0`). Además, usé el operador lógico `&&` para combinar dos condiciones: que el número fuera estrictamente positivo (`numero > 0`) Y que fuera par.

### Pregunta 3 — Ciclos
En el ejercicio 4, utilicé el ciclo `for`. Es el más apropiado para este problema porque se conoce de antemano el número exacto de iteraciones que se deben realizar (desde `1` hasta `n`).

### Pregunta 4 — Arreglos
En C++, cuando un arreglo se pasa como parámetro a una función, este se degrada a un puntero hacia su primer elemento, perdiendo la información sobre su tamaño original. Por lo tanto, es necesario pasar el tamaño como un parámetro adicional para saber cuántos elementos iterar sin acceder a memoria fuera de los límites.

### Pregunta 5 — Referencias
`int& cociente` e `int& residuo` permiten a la función modificar directamente las variables originales declaradas en el `main`. Si se pasaran por valor, la función modificaría únicamente copias locales y los resultados calculados se perderían al finalizar la ejecución de la función.

### Pregunta 6 — Punteros
* `a`: Es la variable puntero que almacena una dirección de memoria.
* `&a`: Es la dirección de memoria donde reside el propio puntero `a`.
* `*a`: Es el operador de desreferenciación, utilizado para acceder o modificar el valor guardado en la dirección de memoria a la que apunta `a`.

### Pregunta 7 — Memoria dinámica
`new[]` solicita al sistema operativo un bloque de memoria en el Heap (montículo) para almacenar un arreglo del tamaño especificado. `delete[]` se encarga de liberar ese bloque entero de memoria cuando ya no se necesita. Es necesario liberar la memoria para evitar fugas de memoria (*memory leaks*), las cuales agotan los recursos del sistema durante la ejecución del programa.

### Pregunta 8 — Análisis
Para el promedio, sumé todos los elementos del arreglo recorriéndolo con un ciclo `for` y dividí el total acumulado entre el tamaño del arreglo (haciendo casting a `double`). Para contar los elementos mayores que un valor dado, iteré sobre el arreglo comparando cada elemento con el valor recibido mediante un condicional `if (arreglo[i] > valor)` e incrementando un contador cada vez que la condición se cumplía.