bool is_armstrong_number(int number) {
    int original = number;
    int digits = 0;
    int sum = 0;

    int temp = number;

    if (number == 0) {
        return true;
    }

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = number;

    while (temp > 0) {
        int digit = temp % 10;

        int power = 1;
        for (int i = 0; i < digits; i++) {
            power *= digit;
        }

        sum += power;
        temp /= 10;
    }

    return sum == original;
}
