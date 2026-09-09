#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int precioMinimo = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < precioMinimo) {
                precioMinimo = prices[i];
            } else {
                int ganancia = prices[i] - precioMinimo;

                if (ganancia > maxProfit) {
                    maxProfit = ganancia;
                }
            }
        }

        return maxProfit;
    }
};
