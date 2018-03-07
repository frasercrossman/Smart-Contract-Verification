//
// Created by fraser on 19/02/18.
//
#include <stdio.h>
#include <inttypes.h>
#include "contract_semantics.h"

#define ARRSIZE(x) (sizeof(x) / sizeof(x[0]))

int main() {
    int8_t result = contract(2);

    return 0;
}

int contract(int N) {
    // This implementation will require the use of a SHA hash function
    // This additional complexity is beyond the scope of the project
    // and should only be returned to if entirely necessary.
}