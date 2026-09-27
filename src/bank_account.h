#pragma once

#include <mutex>
#include <stdexcept>

class bank_account {
private:
    long long balance_amount;
    bool is_open;
    mutable std::mutex mtx;

public:
    bank_account() : balance_amount(0), is_open(false) {}

    void open() {
        std::lock_guard<std::mutex> lock(mtx);
        if (is_open) {
            throw std::domain_error("Account is already open.");
        }
        is_open = true;
        balance_amount = 0;
    }

    void close() {
        std::lock_guard<std::mutex> lock(mtx);
        if (!is_open) {
            throw std::domain_error("Account is already closed.");
        }
        is_open = false;
    }

    long long balance() const {
        std::lock_guard<std::mutex> lock(mtx);
        if (!is_open) {
            throw std::domain_error("Account is closed.");
        }
        return balance_amount;
    }

    void deposit(long long amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (!is_open) {
            throw std::domain_error("Account is closed.");
        }
        if (amount < 0) {
            throw std::domain_error("Cannot deposit negative amounts.");
        }
        balance_amount += amount;
    }

    void withdraw(long long amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (!is_open) {
            throw std::domain_error("Account is closed.");
        }
        if (amount < 0 || amount > balance_amount) {
            throw std::domain_error("Invalid withdrawal amount.");
        }
        balance_amount -= amount;
    }
};

