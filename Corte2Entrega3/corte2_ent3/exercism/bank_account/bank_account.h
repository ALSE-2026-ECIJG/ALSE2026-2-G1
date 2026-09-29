#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H
#include <mutex>
#include <stdexcept>
namespace Bankaccount {
class Bankaccount {
private:
    mutable std::mutex account_mutex;
    long long balance_amount;
    bool is_open;
public:
    Bankaccount();
    ~Bankaccount() = default;
    void open();
    void close();
    void deposit(long long amount);
    void withdraw(long long amount);
    long long balance() const;
};
}
#endif
