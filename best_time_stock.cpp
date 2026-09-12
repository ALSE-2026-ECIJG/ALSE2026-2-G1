#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int precio_minimo = prices[0];
        int ganancia_maxima = 0;
        
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] < precio_minimo) {
                precio_minimo = prices[i];
            } else {
                int ganancia_actual = prices[i] - precio_minimo;
                if (ganancia_actual > ganancia_maxima) {
                    ganancia_maxima = ganancia_actual;
                }
            }
        }
        return ganancia_maxima;
    }
};
