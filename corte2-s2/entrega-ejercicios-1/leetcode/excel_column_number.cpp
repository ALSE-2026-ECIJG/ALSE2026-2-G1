#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int resultado = 0;

        for (char letra : columnTitle) {
            resultado = resultado * 26 + (letra - 'A' + 1);
        }

        return resultado;
    }
};
