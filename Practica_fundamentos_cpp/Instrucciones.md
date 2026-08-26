# Asignación 1 — Fundamentos de C++: funciones, control de flujo y memoria

## 1. Objetivo

En esta asignación se aplicarán los conceptos fundamentales de C++ vistos en clase:

- Tipos de datos y variables.
- Operadores aritméticos, relacionales y lógicos.
- Estructuras de control (`if`, `else`, `for`, `while`).
- Funciones.
- Arreglos.
- Referencias.
- Punteros.
- Memoria dinámica con `new[]` y `delete[]`.

La asignación está diseñada para que se practiquen estos conceptos mediante funciones independientes que puedan ser probadas automáticamente.

> **Importante:** En esta asignación se trabajará en archivos `.cpp`. Todavía no es necesario separar el programa en archivos `.h` y `.cpp`.

---

## 2. Forma de trabajo

Cada ejercicio debe implementarse en un archivo `.cpp` independiente.

La estructura esperada del repositorio es:

```text
asignacion-01/
├── README.md
├── ejercicio01/
│   └── ejercicio01.cpp
├── ejercicio02/
│   └── ejercicio02.cpp
├── ejercicio03/
│   └── ejercicio03.cpp
├── ejercicio04/
│   └── ejercicio04.cpp
├── ejercicio05/
│   └── ejercicio05.cpp
├── ejercicio06/
│   └── ejercicio06.cpp
├── ejercicio07/
│   └── ejercicio07.cpp
├── ejercicio08/
│   └── ejercicio08.cpp
├── ejercicio09/
│   └── ejercicio09.cpp
├── ejercicio10/
│   └── ejercicio10.cpp
└── EXPLICACION.md
```

No deben cambiarse los nombres de las carpetas ni de los archivos.

En cada archivo se encontrará, o se deberá crear, la función o funciones indicadas en el enunciado correspondiente.

### Regla importante sobre las funciones

Las funciones deben conservar exactamente:

- el nombre indicado;
- el tipo de retorno indicado;
- el orden de los parámetros;
- los tipos de los parámetros.

Por ejemplo, si se solicita:

```cpp
int sumar(int a, int b);
```

no se debe cambiar por:

```cpp
double sumar(double a, double b);
```

La evaluación automática utilizará las interfaces especificadas en este documento.

---

# 3. Recomendaciones generales

### 3.1 Código

Se recomienda utilizar nombres de variables claros y evitar código innecesariamente complejo.

Por ejemplo:

```cpp
int suma = 0;
```

es preferible a:

```cpp
int x = 0;
```

cuando `x` representa una suma.

### 3.2 `main()`

Debe utilizarse una función `main()` para probar manualmente las funciones durante el desarrollo, ademas de demostrar el entendimiento y uso de las implementaciones hecas en el flujo principal main.

Sin embargo, la evaluación principal se realizará llamando directamente a las funciones solicitadas.

Por esta razón, **no debe dependerse de `cin` o `cout` para que las funciones funcionen**.

Por ejemplo, para este ejercicio:

```cpp
int sumar(int a, int b);
```

la función debe recibir los datos mediante sus parámetros y devolver el resultado.

No debe solicitar los datos mediante:

```cpp
cin >> a;
```

### 3.3 Librerías

Se utilizarán únicamente las librerías estándar de C++ que sean necesarias.

No deben utilizarse librerías externas.

### 3.4 Restricciones

Para esta asignación no es necesario utilizar:

- clases;
- objetos;
- `std::vector`;
- `std::string` como estructura principal de los ejercicios;
- templates;
- archivos `.h`;
- programación orientada a objetos.

El objetivo es practicar los conceptos fundamentales vistos hasta este momento.

---

# 4. Ejercicios

## Ejercicio 1 — Calculadora básica

**Archivo:** `ejercicio01.cpp`

### Objetivo

Practicar variables, tipos numéricos, operadores aritméticos y funciones.

Implementa las siguientes funciones:

```cpp
int sumar(int a, int b);

int restar(int a, int b);

int multiplicar(int a, int b);

double dividir(int a, int b);
```

### Comportamiento esperado

Ejemplos:

```text
sumar(10, 5)        → 15
restar(10, 5)       → 5
multiplicar(10, 5)  → 50
dividir(10, 5)      → 2.0
dividir(5, 2)       → 2.5
```

La función `dividir()` debe realizar división de punto flotante.

---

## Ejercicio 2 — Conversión de temperatura

**Archivo:** `ejercicio02.cpp`

### Objetivo

Practicar `double`, operaciones aritméticas y funciones.

Implementa:

```cpp
double celsius_a_fahrenheit(double celsius);

double fahrenheit_a_celsius(double fahrenheit);
```

Utiliza las fórmulas:

\[
F = C \times \frac{9}{5} + 32
\]

\[
C = (F - 32) \times \frac{5}{9}
\]

### Ejemplos

```text
celsius_a_fahrenheit(0)     → 32
celsius_a_fahrenheit(100)   → 212

fahrenheit_a_celsius(32)    → 0
fahrenheit_a_celsius(212)   → 100
```

La evaluación utilizará una tolerancia apropiada para resultados de punto flotante.

---

## Ejercicio 3 — Clasificación de números

**Archivo:** `ejercicio03.cpp`

### Objetivo

Practicar estructuras condicionales y operadores lógicos.

Implementa:

```cpp
int clasificar_numero(int numero);

bool es_positivo_par(int numero);
```

#### `clasificar_numero`

Debe retornar:

```text
 1  si el número es positivo
 0  si el número es cero
-1  si el número es negativo
```

Ejemplos:

```text
clasificar_numero(15)  → 1
clasificar_numero(0)   → 0
clasificar_numero(-7)  → -1
```

#### `es_positivo_par`

Debe retornar `true` únicamente cuando el número sea simultáneamente:

- positivo; y
- par.

Ejemplos:

```text
es_positivo_par(2)    → true
es_positivo_par(10)   → true
es_positivo_par(3)    → false
es_positivo_par(-2)   → false
es_positivo_par(0)    → false
```

---

## Ejercicio 4 — Estadísticas de enteros

**Archivo:** `ejercicio04.cpp`

### Objetivo

Practicar ciclos, acumuladores, operadores y funciones.

Implementa:

```cpp
int suma_hasta(int n);

int contar_pares(int n);
```

#### `suma_hasta`

Debe retornar la suma de todos los enteros desde `1` hasta `n`.

Ejemplos:

```text
suma_hasta(1)  → 1
suma_hasta(5)  → 15
suma_hasta(10) → 55
```

#### `contar_pares`

Debe retornar cuántos números pares existen entre `1` y `n`, incluyendo `n` cuando corresponda.

Ejemplos:

```text
contar_pares(1)  → 0
contar_pares(5)  → 2
contar_pares(10) → 5
```

Para las pruebas se utilizarán valores de `n` mayores o iguales a 1.

---

## Ejercicio 5 — Operaciones con arreglos

**Archivo:** `ejercicio05.cpp`

### Objetivo

Practicar arreglos, ciclos, funciones y recorrido de datos.

Implementa:

```cpp
int suma_arreglo(const int arreglo[], int tamano);

int maximo_arreglo(const int arreglo[], int tamano);

bool contiene(const int arreglo[], int tamano, int valor);
```

#### `suma_arreglo`

Retorna la suma de todos los elementos.

Ejemplo:

```text
[4, 8, 2, 10, 3] → 27
```

#### `maximo_arreglo`

Retorna el elemento de mayor valor.

Ejemplo:

```text
[4, 8, 2, 10, 3] → 10
```

#### `contiene`

Retorna `true` si `valor` aparece en el arreglo y `false` en caso contrario.

Ejemplo:

```text
[4, 8, 2, 10, 3], 8   → true
[4, 8, 2, 10, 3], 20  → false
```

### Consideraciones

En las pruebas el tamaño del arreglo será mayor que cero.

---

## Ejercicio 6 — Transformación de un arreglo

**Archivo:** `ejercicio06.cpp`

### Objetivo

Practicar modificación de arreglos y paso de información a funciones.

Implementa:

```cpp
void multiplicar_arreglo(int arreglo[], int tamano, int factor);
```

La función debe multiplicar cada elemento del arreglo por `factor`.

Ejemplo:

```text
Arreglo inicial:
[1, 2, 3, 4]

factor = 3

Arreglo después de la función:
[3, 6, 9, 12]
```

La función debe modificar directamente el arreglo recibido.

No debe crear ni retornar un segundo arreglo.

---

## Ejercicio 7 — División entera

**Archivo:** `ejercicio07.cpp`

### Objetivo

Practicar división entera, operador módulo (`%`) y referencias.

Implementa:

```cpp
void dividir_entero(
    int dividendo,
    int divisor,
    int& cociente,
    int& residuo
);
```

La función debe calcular:

\[
dividendo = divisor \times cociente + residuo
\]

Ejemplo:

```text
dividendo = 17
divisor = 5

cociente = 3
residuo = 2
```

Otros ejemplos:

```text
10 / 2 → cociente = 5, residuo = 0
20 / 7 → cociente = 2, residuo = 6
17 / 5 → cociente = 3, residuo = 2
```

Para esta asignación se garantiza que el divisor será diferente de cero.

---

## Ejercicio 8 — Intercambio mediante punteros

**Archivo:** `ejercicio08.cpp`

### Objetivo

Practicar punteros, direcciones de memoria y desreferenciación.

Implementa:

```cpp
void intercambiar(int* a, int* b);
```

La función debe intercambiar los valores almacenados en las dos variables.

Ejemplo:

```cpp
int x = 10;
int y = 20;

intercambiar(&x, &y);
```

Después de ejecutar la función:

```text
x = 20
y = 10
```

Otro ejemplo:

```text
x = -5
y = 8

intercambiar(&x, &y)

x = 8
y = -5
```

### Restricción

El intercambio debe realizarse modificando las variables originales mediante los punteros recibidos.

No debe retornar un valor para realizar el intercambio.

---

## Ejercicio 9 — Arreglo dinámico de enteros

**Archivo:** `ejercicio09.cpp`

### Objetivo

Practicar memoria dinámica y punteros.

Implementa:

```cpp
int* crear_arreglo(int tamano);

void inicializar_arreglo(
    int* arreglo,
    int tamano,
    int valor
);

void destruir_arreglo(int* arreglo);
```

#### `crear_arreglo`

Debe reservar dinámicamente un arreglo de `tamano` enteros y retornar un puntero al primer elemento.

Debe utilizar:

```cpp
new[]
```

#### `inicializar_arreglo`

Debe asignar `valor` a todos los elementos.

Ejemplo conceptual:

```text
crear_arreglo(5)

→ [?, ?, ?, ?, ?]

inicializar_arreglo(..., 5, 10)

→ [10, 10, 10, 10, 10]
```

#### `destruir_arreglo`

Debe liberar correctamente la memoria reservada por `crear_arreglo`.

Debe utilizar:

```cpp
delete[]
```

### Restricciones

No debe utilizarse:

```cpp
std::vector
```

ni memoria estática para reemplazar la reserva dinámica solicitada.

---

## Ejercicio 10 — Análisis de datos numéricos

**Archivo:** `ejercicio10.cpp`

### Objetivo

Integrar funciones, ciclos, arreglos, operaciones aritméticas y valores de punto flotante.

Implementa:

```cpp
double promedio_arreglo(const int arreglo[], int tamano);

int contar_mayores_que(
    const int arreglo[],
    int tamano,
    double valor
);
```

#### `promedio_arreglo`

Debe calcular el promedio aritmético de los elementos.

Ejemplo:

```text
[2, 4, 6, 8, 10]

promedio = 6.0
```

#### `contar_mayores_que`

Debe contar cuántos elementos del arreglo son estrictamente mayores que `valor`.

Ejemplo:

```text
Arreglo:
[2, 4, 6, 8, 10]

valor:
6

resultado:
2
```

porque únicamente `8` y `10` son mayores que `6`.

### Consideraciones

En las pruebas el arreglo tendrá al menos un elemento.

---

# 5. Pruebas y casos límite

No debe asumirse que los ejemplos anteriores son los únicos casos que se probarán.

Además de los casos normales, se utilizarán casos como:

- números negativos;
- cero;
- arreglos con valores repetidos;
- arreglos con valores negativos;
- arreglos de un solo elemento;
- factores negativos;
- valores grandes dentro de los límites del tipo de dato;
- diferentes tamaños de arreglo.

Por ejemplo, para:

```cpp
bool contiene(const int arreglo[], int tamano, int valor);
```

no será suficiente comprobar únicamente:

```text
[1, 2, 3], 2
```

También se recomienda probar:

```text
[1, 2, 3], 5
[1, 1, 1], 1
[-5, -2, -10], -2
[7], 7
[7], 3
```

Los casos de prueba públicos estarán disponibles durante el desarrollo. También existirán pruebas adicionales utilizadas para la evaluación.

---

# 6. Archivo de explicación

Además de los archivos `.cpp`, debe entregarse:

```text
EXPLICACION.md
```

Este archivo debe estar escrito con palabras propias.

No se busca repetir definiciones de un libro o de Internet. Se debe explicar las decisiones adoptadas en la implementación.

Responde como mínimo las siguientes preguntas.

### Pregunta 1 — Tipos

En el ejercicio 1, ¿por qué `dividir()` retorna `double` mientras que las otras operaciones retornan `int`?

### Pregunta 2 — Operadores

En el ejercicio 3, explica cómo utilizaste los operadores `%`, `&&`, `||` o `!`.

### Pregunta 3 — Ciclos

En el ejercicio 4, explica qué ciclo utilizaste y por qué consideras que es apropiado para el problema.

### Pregunta 4 — Arreglos

En el ejercicio 5, ¿por qué la función recibe tanto el arreglo como su tamaño?

### Pregunta 5 — Referencias

En el ejercicio 7, explica qué función cumplen:

```cpp
int& cociente
int& residuo
```

¿Qué ocurriría si se utilizaran parámetros por valor?

### Pregunta 6 — Punteros

En el ejercicio 8, explica la diferencia entre:

```cpp
a
&a
*a
```

### Pregunta 7 — Memoria dinámica

En el ejercicio 9, explica la diferencia entre:

```cpp
new[]
```

y:

```cpp
delete[]
```

¿Por qué es necesario liberar la memoria?

### Pregunta 8 — Análisis

En el ejercicio 10, explica cómo calculaste el promedio y cómo determinaste cuáles elementos son mayores que un valor dado.

---

# 7. Entrega

La entrega se realizará mediante tu repositorio de GitHub.

Antes de la fecha límite verifique que:

1. Todos los archivos `.cpp` estén presentes.
2. `EXPLICACION.md` esté completo.
3. El código compile correctamente.
4. No hayas cambiado los nombres o firmas de las funciones solicitadas.
5. Tus cambios hayan sido enviados (`push`) al repositorio remoto.
6. Las pruebas proporcionadas para los ejercicios pasen correctamente.

La última versión enviada al repositorio antes de la fecha límite será la considerada para la evaluación.

---

# 8. Criterios de evaluación

La calificación tendrá dos componentes: evaluación automática y evaluación manual.

## Evaluación automática — 70%

| Componente | Porcentaje |
|---|---:|
| Compilación y estructura del código | 10% |
| Funcionamiento de los ejercicios 1–4 | 15% |
| Funcionamiento de los ejercicios 5–7 | 20% |
| Funcionamiento de los ejercicios 8–10 | 25% |
| **Total** | **70%** |

Las pruebas automáticas incluirán casos normales y casos límite.

## Evaluación manual — 30%

| Componente | Porcentaje |
|---|---:|
| Explicación técnica (`EXPLICACION.md`) | 10% |
| Claridad y organización del código | 10% |
| Comprensión de las soluciones | 10% |
| **Total** | **30%** |



# 9. Ejercicios opcionales — Exercism

Como actividad adicional puedes utilizar la plataforma Exercism para practicar C++.

Estos ejercicios son **opcionales y no reemplazan los diez ejercicios de esta asignación**.

Se recomienda seleccionar al menos tres de los siguientes:

- Hello World
- Lasagna
- Annalyn's Infiltration
- Pac-Man
- Cars, Assemble!


Los ejercicios de Exercism pueden servir para practicar conceptos similares desde otra perspectiva. 
La correcta implementación y su respectiva evidencia pueden ayudar a obtener una ligera bonificación sobre las asignación principal.

---

# 10. Recordatorio final

El objetivo principal de esta asignación no es solamente obtener programas que produzcan resultados correctos.

Se busca desarrollar la capacidad de:

- leer una especificación;
- diseñar una función;
- elegir tipos de datos apropiados;
- utilizar estructuras de control;
- trabajar con arreglos;
- comprender referencias y punteros;
- administrar memoria dinámica;
- probar el código;
- interpretar errores;
- explicar las decisiones de implementación.

El código funcional es importante, pero **comprender por qué funciona constituye una parte fundamental de la asignación**.
