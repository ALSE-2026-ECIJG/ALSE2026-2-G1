#include <iostream>
#include "clock.h"

using namespace std;

int main() {
    cout << "--- Simulacion Clock (Exercism) ---" << endl;

    // 1. Crear un reloj a las 08:00
    Clock clock1(8, 0);
    cout << "Hora inicial: " << clock1.toString() << endl; // 08:00

    // 2. Sumar 3 horas y media (210 minutos)
    Clock clock2 = clock1.add(210);
    cout << "Hora + 210 min: " << clock2.toString() << endl; // 11:30

    // 3. Restar 2 horas y 45 minutos (165 minutos)
    Clock clock3 = clock2.subtract(165);
    cout << "Hora - 165 min: " << clock3.toString() << endl; // 08:45

    // 4. Probar el desbordamiento de día (sumar 24 horas)
    Clock clock4 = clock1.add(1440);
    cout << "Hora + 1440 min (24h): " << clock4.toString() << endl; // 08:00

    // 5. Probar la resta con desbordamiento hacia atrás
    Clock clock5(1, 0);
    Clock clock6 = clock5.subtract(90);
    cout << "Hora inicial: " << clock5.toString() << endl; // 01:00
    cout << "Hora - 90 min: " << clock6.toString() << endl; // 23:30

    // 6. Probar operadores de comparación
    Clock clock7(8, 0);
    Clock clock8(8, 0);
    cout << "Son iguales 08:00 == 08:00? " << (clock7 == clock8 ? "Si" : "No") << endl;
    cout << "Son diferentes 08:00 != 08:01? " << (clock7 != Clock(8, 1) ? "Si" : "No") << endl;

    return 0;
}
