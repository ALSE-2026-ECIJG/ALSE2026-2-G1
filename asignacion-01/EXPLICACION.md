# Explicación — Asignación 01: Fundamentos de C++

## Pregunta 1

En el ejercicio 1, la función `dividir()` retorna un `double` porque el resultado de una división no necesariamente es un número entero.

Por ejemplo, al realizar `10 / 5`, el resultado es `2`, pero al realizar `5 / 2`, el resultado correcto es `2.5`. Por esta razón, la función utiliza `double` para poder representar también la parte decimal del resultado.

En cambio, las funciones `sumar()`, `restar()` y `multiplicar()` trabajan con números enteros y sus resultados también son enteros, por lo que utilizan `int`.

Además, en la función `dividir()` se realiza la conversión necesaria para que la división sea de punto flotante y no una división entera.

---

## Pregunta 2 

En el ejercicio 3 se utilizaron operadores aritméticos, relacionales y lógicos para clasificar los números.

Para determinar si un número es par se utiliza el operador `%`, que permite obtener el residuo de una división. Por ejemplo, si `numero % 2 == 0`, significa que el número es divisible entre 2 y, por lo tanto, es par.

Para la función `es_positivo_par()` se utiliza el operador lógico `&&`, porque se deben cumplir dos condiciones al mismo tiempo: que el número sea positivo y que sea par.

Por ejemplo:

```cpp
numero > 0 && numero % 2 == 0
```

Si cualquiera de las dos condiciones es falsa, el resultado será `false`.

---

## Pregunta 

En el ejercicio 4 utilicé un ciclo `for` porque se conoce desde el comienzo el rango de valores que se debe recorrer, desde `1` hasta `n`.

En `suma_hasta()` el ciclo permite recorrer todos los números y acumularlos en una variable `suma`.

En `contar_pares()` se utiliza un recorrido similar, pero en cada iteración se verifica si el número es par mediante el operador `%`. Si lo es, se incrementa un contador.

Considero que `for` es apropiado porque permite establecer claramente el valor inicial, la condición de finalización y el incremento del contador en una sola estructura.

---

## Pregunta 

En el ejercicio 5 las funciones reciben tanto el arreglo como su tamaño porque un arreglo en C++ no contiene dentro de sí información que permita conocer directamente cuántos elementos tiene cuando se recibe como parámetro.

Por ejemplo:

```cpp
int suma_arreglo(const int arreglo[], int tamano);
```

El parámetro `arreglo` permite acceder a los elementos, mientras que `tamano` indica cuántos elementos se deben recorrer.

Esto permite utilizar un ciclo como:

```cpp
for (int i = 0; i < tamano; i++)
```

y evitar acceder a posiciones que están fuera del arreglo.

---

## Pregunta 

En el ejercicio 7, los parámetros:

```cpp
int& cociente
int& residuo
```

son referencias. Esto permite que la función modifique directamente las variables originales que fueron enviadas desde `main()`.

Por ejemplo, cuando se ejecuta:

```cpp
dividir_entero(17, 5, cociente, residuo);
```

la función puede guardar el resultado directamente en las variables `cociente` y `residuo`.

Si se utilizaran parámetros por valor, la función recibiría copias de las variables. En ese caso, aunque se modificaran esas copias dentro de la función, las variables originales de `main()` no cambiarían.

Las referencias permiten utilizar los parámetros como una forma de devolver más de un resultado desde la misma función.

---

## Pregunta 

En el ejercicio 8 se trabaja con punteros para poder modificar directamente las variables originales.

Si tenemos:

```cpp
int x = 10;
int* a = &x;
```

podemos diferenciar:

* `a`: contiene la dirección de memoria de la variable `x`.
* `&a`: representa la dirección de memoria donde está almacenado el propio puntero `a`.
* `*a`: permite acceder al valor almacenado en la dirección a la que apunta `a`. En este caso, corresponde al valor de `x`.

En la función `intercambiar()` se utilizan los punteros para acceder y modificar los valores originales:

```cpp
int temporal = *a;
*a = *b;
*b = temporal;
```

De esta manera se pueden intercambiar los valores de las variables sin tener que retornarlas.

---

## Pregunta 

En el ejercicio 9 se utiliza `new[]` para reservar memoria dinámicamente para un arreglo.

Por ejemplo:

```cpp
int* arreglo = new int[tamano];
```

Esto permite crear un arreglo cuyo tamaño se determina durante la ejecución del programa.

Después de utilizar esa memoria, es necesario liberarla. Para eso se utiliza:

```cpp
delete[] arreglo;
```

La razón de liberar la memoria es evitar que quede memoria reservada que ya no se está utilizando. Si un programa reserva memoria dinámicamente y nunca la libera, puede producirse una fuga de memoria (*memory leak*).

En este ejercicio se utiliza `new[]` para reservar un arreglo y `delete[]` para liberar correctamente ese mismo arreglo.

---

## Pregunta 

En el ejercicio 10, para calcular el promedio primero se recorren todos los elementos del arreglo y se acumula su suma.

Después se divide la suma entre el tamaño del arreglo:

```cpp
return static_cast<double>(suma) / tamano;
```

Se utiliza `static_cast<double>` para asegurar que la división se realice como una operación de punto flotante y pueda producir resultados decimales.

Para determinar cuáles elementos son mayores que un valor dado, se recorre nuevamente el arreglo y se compara cada elemento con `valor`.

La condición utilizada es:

```cpp
arreglo[i] > valor
```

Cada vez que esta condición se cumple, se incrementa un contador. Al finalizar el recorrido, el contador representa la cantidad de elementos que son estrictamente mayores que el valor recibido.

Por ejemplo, para el arreglo:

```text
[2, 4, 6, 8, 10]
```

y el valor `6`, únicamente `8` y `10` cumplen la condición, por lo que el resultado es `2`.
