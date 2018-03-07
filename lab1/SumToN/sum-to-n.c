#include <stdio.h>
#include <inttypes.h>

int sum_to_n(int8_t N) {
    int8_t s = 0;
    int8_t n = N;
    while (n > 0) {
        s = s + n; // Line of overflow!
        n = n - 1;
    }
    return s;
}

int main() {
    printf("Running sum to n\n");
    int8_t N = 35;
    printf("Sum to %d = %d\n", N, sum_to_n(N));
    return 0;
}

