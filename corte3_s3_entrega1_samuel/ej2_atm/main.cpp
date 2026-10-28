#include <iostream>
#include <vector>

using namespace std;

class ATM {
private:
    vector<long long> billetes; // Índices: 0->20, 1->50, 2->100, 3->200, 4->500
    const int denominaciones[5] = {20, 50, 100, 200, 500};

public:
    ATM() : billetes(5, 0) {}

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) {
            billetes[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> resultado(5, 0);
        vector<long long> copiaBilletes = billetes; // Copia para no modificar si falla
        long long restante = amount;

        // Intentar con denominaciones de mayor a menor
        for (int i = 4; i >= 0; --i) {
            // Cuántos billetes de esta denominación necesitamos
            long long necesarios = restante / denominaciones[i];
            // Cuántos podemos usar realmente (no podemos usar más de los que hay)
            long long usar = min(necesarios, copiaBilletes[i]);
            
            resultado[i] = usar;
            restante -= usar * denominaciones[i];
        }

        // Si no pudimos completar el monto exacto, rechazamos la operación
        if (restante > 0) {
            return {-1}; 
        }

        // Si llegamos aquí, la operación fue exitosa. Actualizamos inventario real.
        for (int i = 0; i < 5; ++i) {
            billetes[i] -= resultado[i];
        }

        return resultado;
    }
};

int main() {
    ATM atm;
    
    cout << "--- Simulacion Ejemplo 1 (LeetCode 2241) ---" << endl;

    // 1. Depositar: [0,0,1,2,1] -> 1 de 100, 2 de 200, 1 de 500
    atm.deposit({0, 0, 1, 2, 1});
    cout << "Deposito 1: [0,0,1,2,1]" << endl;

    // 2. Retirar 600 -> Deberia usar 1 de 500 + 1 de 100 -> [0,0,1,0,1]
    vector<int> r1 = atm.withdraw(600);
    cout << "Retiro 600 -> Esperado [0,0,1,0,1]. Obtenido: ";
    for (int x : r1) cout << x << " ";
    cout << endl;

    // 3. Depositar: [0,1,0,1,1] -> 1 de 50, 1 de 200, 1 de 500
    atm.deposit({0, 1, 0, 1, 1});
    cout << "Deposito 2: [0,1,0,1,1]" << endl;

    // 4. Retirar 600 -> Deberia fallar -> [-1]
    // Explicacion: usara el de 500, quedan 100. No puede usar el de 200. Falla.
    vector<int> r2 = atm.withdraw(600);
    cout << "Retiro 600 -> Esperado [-1]. Obtenido: ";
    for (int x : r2) cout << x << " ";
    cout << endl;

    // 5. Retirar 550 -> Deberia usar 1 de 500 + 1 de 50 -> [0,1,0,0,1]
    vector<int> r3 = atm.withdraw(550);
    cout << "Retiro 550 -> Esperado [0,1,0,0,1]. Obtenido: ";
    for (int x : r3) cout << x << " ";
    cout << endl;

    return 0;
}
