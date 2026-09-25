#include <iostream>
#include <cmath>

using namespace std;

bool isArmstrong(int n) {
    if (n < 0) return false;
    int original = n;
    int numDigits = 0;

    // Contar dígitos
    int temp = n;
    while (temp > 0) {
        numDigits++;
        temp /= 10;
    }
    if (n == 0) numDigits = 1;

    // Sumar dígitos elevados a la potencia
    int sum = 0;
    temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, numDigits);
        temp /= 10;
    }

    return sum == original;
}

int main() {
    int number = 153;
    if (isArmstrong(number)) {
        cout << number << " es un numero de Armstrong." << endl;
    } else {
        cout << number << " NO es un numero de Armstrong." << endl;
    }
    return 0;
}

