//
// Created by fraser on 22/02/18.
//
#include <stdio.h>
#include <inttypes.h>
#include "contract_semantics.h"

#define ARRSIZE(x) (sizeof(x) / sizeof(x[0]))

int main() {
    int numerator = 10;
    int denominator = 0;
    printf("Running div by zero\n");
    printf("%d / %d = %d\n", numerator, denominator, contract(numerator, denominator));

    return 0;
}

int contract(int numerator, int denominator) {
    // User input should be stored on the stack
    push(0xDEADBEEF); // jump tag used to format the return value
    push(numerator);
    push(denominator);
    // ---

    /* "solidity/DivByZero.sol":119:122  int */
    push(0x0);
    /* "solidity/DivByZero.sol":153:164  denominator */
    dup(2);
    /* "solidity/DivByZero.sol":141:150  numerator */
    dup(4);

    /* Check added by Solidity to throw a runtime exception on division by zero */
    /* "solidity/DivByZero.sol":141:164  numerator / denominator */
    /*
    dup(2);
    iszero();
    iszero();
    tag_7
    jumpi
    invalid
    tag_7:
    */

    sdiv();
    /* "solidity/DivByZero.sol":134:164  return numerator / denominator */
    swap(1);
    pop();
    /* "solidity/DivByZero.sol":51:171  function divide(int numerator, int denominator) public pure returns(int) {... */
    swap(3);
    swap(2);
    pop();
    pop();


    pop();  // jump to the value on the top of the stack (0xDEADBEEF)
    //jump	// out

    // Manipulates the value so that it is correctly returned
    return pop();
}
