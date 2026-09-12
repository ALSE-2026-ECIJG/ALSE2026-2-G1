namespace armstrong_numbers {

    // Función auxiliar manual para potencias de enteros
    int elevar_potencia(int base, int exp) {
        int resultado = 1;
        for (int i = 0; i < exp; ++i) {
            resultado *= base;
        }
        return resultado;
    }

    bool is_armstrong_number(int number) {
        if (number < 0) return false;
        
        // 1. Contar número de dígitos
        int temp = number;
        int num_digitos = 0;
        if (temp == 0) num_digitos = 1;
        while (temp > 0) {
            num_digitos++;
            temp /= 10;
        }

        // 2. Sumar la potencia de cada dígito
        temp = number;
        int suma = 0;
        while (temp > 0) {
            int digito = temp % 10;
            suma += elevar_potencia(digito, num_digitos);
            temp /= 10;
        }

        return suma == number;
    }

}  // namespace armstrong_numbers
