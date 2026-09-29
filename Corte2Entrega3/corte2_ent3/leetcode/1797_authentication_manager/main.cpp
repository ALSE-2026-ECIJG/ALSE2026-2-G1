#include <iostream>
#include "AuthenticationManager.h"

int main() {
    // Ejemplo oficial del enunciado de LeetCode 1797
    AuthenticationManager am(5); // ttl = 5

    am.renew("aaa", 1);
    std::cout << "renew(aaa, 1) -> no existe ningun token, se ignora" << std::endl;

    am.generate("aaa", 2);
    std::cout << "generate(aaa, 2) -> aaa expira en 7" << std::endl;

    std::cout << "countUnexpiredTokens(6) = " << am.countUnexpiredTokens(6) << " (esperado 1)" << std::endl;

    am.generate("bbb", 7);
    std::cout << "generate(bbb, 7) -> bbb expira en 12" << std::endl;

    am.renew("aaa", 8);
    std::cout << "renew(aaa, 8) -> aaa ya expiro en 7 (8 >= 7), se ignora" << std::endl;

    am.renew("bbb", 10);
    std::cout << "renew(bbb, 10) -> bbb aun vigente (expiraba en 12), se renueva y ahora expira en 15" << std::endl;

    std::cout << "countUnexpiredTokens(15) = " << am.countUnexpiredTokens(15) << " (esperado 0)" << std::endl;

    return 0;
}
