#include <iostream>
#include <stdexcept>
#include <mutex>
#include <thread>
#include <vector>

class BankAccount {
private:
    int balanceAmount;
    bool isOpen;
    mutable std::mutex mtx;

    void ensureOpen() const {
        if (!isOpen) {
            throw std::runtime_error("Account is closed");
        }
    }

public:
    BankAccount() : balanceAmount(0), isOpen(false) {}

    void open() {
        std::lock_guard<std::mutex> lock(mtx);
        if (isOpen) {
            throw std::runtime_error("Account is already open");
        }
        isOpen = true;
        balanceAmount = 0;
    }

    void close() {
        std::lock_guard<std::mutex> lock(mtx);
        if (!isOpen) {
            throw std::runtime_error("Account is already closed");
        }
        isOpen = false;
        balanceAmount = 0;
    }

    int balance() const {
        std::lock_guard<std::mutex> lock(mtx);
        ensureOpen();
        return balanceAmount;
    }

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        ensureOpen();
        if (amount < 0) {
            throw std::runtime_error("Cannot deposit negative amount");
        }
        balanceAmount += amount;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        ensureOpen();
        if (amount < 0) {
            throw std::runtime_error("Cannot withdraw negative amount");
        }
        if (amount > balanceAmount) {
            throw std::runtime_error("Insufficient funds");
        }
        balanceAmount -= amount;
    }
};

void testSequential() {
    std::cout << "--- Pruebas secuenciales ---" << std::endl;

    BankAccount acc;

    try {
        acc.balance();
        std::cout << "ERROR: balance en cuenta cerrada no lanzo excepcion" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "balance() en cuenta cerrada: " << e.what() << std::endl;
    }

    acc.open();
    std::cout << "open() -> cuenta abierta" << std::endl;
    std::cout << "balance() = " << acc.balance() << std::endl;

    try {
        acc.open();
        std::cout << "ERROR: open() dos veces no lanzo excepcion" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "open() dos veces: " << e.what() << std::endl;
    }

    acc.deposit(100);
    std::cout << "deposit(100) -> balance = " << acc.balance() << std::endl;

    try {
        acc.deposit(-50);
        std::cout << "ERROR: deposit(-50) no lanzo excepcion" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "deposit(-50): " << e.what() << std::endl;
    }

    acc.withdraw(30);
    std::cout << "withdraw(30) -> balance = " << acc.balance() << std::endl;

    try {
        acc.withdraw(200);
        std::cout << "ERROR: withdraw(200) no lanzo excepcion" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "withdraw(200) sin fondos: " << e.what() << std::endl;
    }

    acc.close();
    std::cout << "close() -> cuenta cerrada" << std::endl;

    try {
        acc.deposit(10);
        std::cout << "ERROR: deposit en cuenta cerrada no lanzo excepcion" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "deposit en cuenta cerrada: " << e.what() << std::endl;
    }

    try {
        acc.close();
        std::cout << "ERROR: close() dos veces no lanzo excepcion" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "close() dos veces: " << e.what() << std::endl;
    }
}

void testConcurrent() {
    std::cout << "\n--- Pruebas concurrentes ---" << std::endl;

    BankAccount acc;
    acc.open();

    const int numThreads = 10;
    const int operationsPerThread = 1000;
    const int amountPerOp = 1;

    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back([&acc]() {
            for (int j = 0; j < operationsPerThread; ++j) {
                acc.deposit(amountPerOp);
            }
        });
    }

    for (auto& t : threads) {
        t.join();
    }

    int finalBalance = acc.balance();
    int expected = numThreads * operationsPerThread * amountPerOp;

    std::cout << "10 hilos x 1000 depositos de 1 unidad" << std::endl;
    std::cout << "Balance final: " << finalBalance << std::endl;
    std::cout << "Balance esperado: " << expected << std::endl;

    if (finalBalance == expected) {
        std::cout << "PRUEBA CONCURRENTE: PASS (sin condiciones de carrera)" << std::endl;
    } else {
        std::cout << "PRUEBA CONCURRENTE: FAIL" << std::endl;
    }
}

int main() {
    std::cout << "=== Exercism: Bank Account ===\n" << std::endl;

    testSequential();
    testConcurrent();

    std::cout << "\n=== Fin de las pruebas ===" << std::endl;
    return 0;
}
