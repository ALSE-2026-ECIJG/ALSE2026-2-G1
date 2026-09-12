#include <string>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        long long resultado = 0;
        for (int i = 0; i < columnTitle.length(); ++i) {
            char c = columnTitle[i];
            int valor = c - 'A' + 1;
            resultado = resultado * 26 + valor;
        }
        return static_cast<int>(resultado);
    }
};
