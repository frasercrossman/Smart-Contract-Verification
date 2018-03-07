#include <stdio.h>
#include <math.h>

int div_by_zero(int numerator, int denominator) {
    return (int) numerator / denominator;
}

int main() {
    printf("Running div by zero\n");
    int numerator = 10;
    int denominator = 0;
    printf("%d / %d = %d\n", numerator,
                             denominator,
                             div_by_zero(numerator, denominator));
    return 0;
}

