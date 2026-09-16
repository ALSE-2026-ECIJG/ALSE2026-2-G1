#include <string>
#include <stdexcept>
#include <string_view>

namespace hamming {
    int compute(std::string_view dna1, std::string_view dna2) {
        if (dna1.size() != dna2.size()) {
            throw std::domain_error("Las cadenas deben tener la misma longitud.");
        }
        
        int distance = 0;
        for (size_t i = 0; i < dna1.size(); ++i) {
            if (dna1[i] != dna2[i]) {
                distance++;
            }
        }
        return distance;
    }
}
