#include <iostream>
#include "bank_account.h"

int main() {
    Bankaccount::Bankaccount cuenta;

    cuenta.open();
    std::cout << "Cuenta abierta. Saldo inicial: " << cuenta.balance() << std::endl;

    cuenta.deposit(100);
    std::cout << "Deposito de 100. Saldo: " << cuenta.balance() << std::endl;

    cuenta.withdraw(30);
    std::cout << "Retiro de 30. Saldo: " << cuenta.balance() << std::endl;

    try {
        cuenta.withdraw(1000);
    } catch (const std::exception& e) {
        std::cout << "Error esperado al retirar mas del saldo: " << e.what() << std::endl;
    }

    cuenta.close();
    std::cout << "Cuenta cerrada." << std::endl;

    try {
        cuenta.balance();
    } catch (const std::exception& e) {
        std::cout << "Error esperado al consultar saldo de cuenta cerrada: " << e.what() << std::endl;
    }

    return 0;
}
