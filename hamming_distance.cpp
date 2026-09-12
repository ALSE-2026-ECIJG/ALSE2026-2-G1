#include <string>

namespace hamming {

    int compute(const std::string& strand_a, const std::string& strand_b) {
        // Validación manual de longitud
        if (strand_a.length() != strand_b.length()) {
            return -1; // Código de error si no se permite lanzar std::domain_error
        }
        
        int distancia = 0;
        for (size_t i = 0; i < strand_a.length(); ++i) {
            if (strand_a[i] != strand_b[i]) {
                distancia++;
            }
        }
        return distancia;
    }

}  // namespace hamming
