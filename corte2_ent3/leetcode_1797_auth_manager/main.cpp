#include <iostream>
#include <string>
#include <unordered_map>

class AuthenticationManager {
private:
    int timeToLive;
    std::unordered_map<std::string, int> expireTime;

public:
    AuthenticationManager(int ttl) : timeToLive(ttl) {}

    void generate(const std::string& tokenId, int currentTime) {
        expireTime[tokenId] = currentTime + timeToLive;
    }

    void renew(const std::string& tokenId, int currentTime) {
        auto it = expireTime.find(tokenId);
        if (it == expireTime.end()) return;
        if (it->second <= currentTime) return;
        it->second = currentTime + timeToLive;
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (const auto& pair : expireTime) {
            if (pair.second > currentTime) count++;
        }
        return count;
    }
};

int main() {
    std::cout << "=== LeetCode 1797: Design Authentication Manager ===\n" << std::endl;

    AuthenticationManager auth(5);

    std::cout << "AuthenticationManager(5)" << std::endl;

    std::cout << "renew(\"aaa\", 1) -> token no existe, sin efecto" << std::endl;
    auth.renew("aaa", 1);

    std::cout << "generate(\"aaa\", 2) -> expira en 7" << std::endl;
    auth.generate("aaa", 2);

    std::cout << "countUnexpiredTokens(6) = " << auth.countUnexpiredTokens(6)
              << " (esperado 1)" << std::endl;

    std::cout << "generate(\"bbb\", 7) -> expira en 12" << std::endl;
    auth.generate("bbb", 7);

    std::cout << "renew(\"aaa\", 8) -> aaa expiro en 7, sin efecto" << std::endl;
    auth.renew("aaa", 8);

    std::cout << "renew(\"bbb\", 10) -> bbb ahora expira en 15" << std::endl;
    auth.renew("bbb", 10);

    std::cout << "countUnexpiredTokens(15) = " << auth.countUnexpiredTokens(15)
              << " (esperado 0)" << std::endl;

    std::cout << "\n=== Fin de las pruebas ===" << std::endl;
    return 0;
}
