#include "bank_account.h"
namespace Bankaccount {
Bankaccount::Bankaccount() : balance_amount(0), is_open(false) {}
void Bankaccount::open() {
    std::lock_guard<std::mutex> lock(account_mutex);
    if (is_open) {
        throw std::runtime_error("La cuenta ya está abierta");
    }
    is_open = true;
    balance_amount = 0;
}
void Bankaccount::close() {
    std::lock_guard<std::mutex> lock(account_mutex);
    if (!is_open) {
        throw std::runtime_error("La cuenta ya está cerrada");
    }
    is_open = false;
}
void Bankaccount::deposit(long long amount) {
    std::lock_guard<std::mutex> lock(account_mutex);
    if (!is_open || amount < 0) {
        throw std::runtime_error("Operación no válida");
    }
    balance_amount += amount;
}
void Bankaccount::withdraw(long long amount) {
    std::lock_guard<std::mutex> lock(account_mutex);
    if (!is_open || amount < 0 || amount > balance_amount) {
        throw std::runtime_error("Operación no válida o fondos insuficientes");
    }
    balance_amount -= amount;
}
long long Bankaccount::balance() const {
    std::lock_guard<std::mutex> lock(account_mutex);
    if (!is_open) {
        throw std::runtime_error("No se puede consultar el saldo de una cuenta cerrada");
    }
    return balance_amount;
}
}
