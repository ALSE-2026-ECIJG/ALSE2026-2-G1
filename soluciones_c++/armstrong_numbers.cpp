#include <cmath>
#include <string>

namespace armstrong_numbers {
    bool is_armstrong_number(int candidate) {
        std::string s = std::to_string(candidate);
        int n = s.length();
        long long sum = 0;
        
        for (char c : s) {
            int digit = c - '0';
            sum += std::pow(digit, n);
        }
        return sum == candidate;
    }
}
