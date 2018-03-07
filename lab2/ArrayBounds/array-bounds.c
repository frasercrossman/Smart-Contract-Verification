#include <stdio.h>
#include <inttypes.h>

int populate_array(unsigned int value_count) {
    unsigned int a[10];

    for(unsigned int i = 0; i < value_count; i++) {
        a[i] = 0x01;
    }
}

int main() {
    printf("Running array access\n");
    int value_count = 15;
    printf("Adding %d values to array of length %d\n", value_count, 10);
    populate_array(value_count);

    return 0;
}

