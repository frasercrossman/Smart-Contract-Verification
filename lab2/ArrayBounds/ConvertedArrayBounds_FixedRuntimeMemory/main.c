//
// Created by fraser on 22/02/18.
//
#include <stdio.h>
#include <inttypes.h>
#include "contract_semantics.h"

#define ARRSIZE(x) (sizeof(x) / sizeof(x[0]))
int contract(unsigned int value_count);

int main() {
    int value_count = 10;
    printf("Running array access\n");
    printf("Adding %d values to array of length %d\n", value_count, 10);
    contract(value_count);

    return 0;
}

int contract(unsigned int value_count) {
    // Initialize the size of memory and storage
    initialise_memory();
    push(0x80);             // Size of memory, in memory (maybe)
    push(0x40);
    mstore();

    // Initialize stack as it is in Remix
    push(0x3a079db0);       // Call data (function signature)
    push(0x62);
    push(value_count);              // Call data (value)
    push(0x60);

    tag_4:
    //stop

    tag_5:
    /* "solidity/LocalArrayAccessViolation.sol":191:206  uint[] memory a */
    //tag_6
    //jump	// in(tag_7)

    tag_6:
    /* "solidity/LocalArrayAccessViolation.sol":296:305  uint256 i */
    push(0x0);
    /* "solidity/LocalArrayAccessViolation.sol":220:222  10 */
    push(0xa);
    /* "solidity/LocalArrayAccessViolation.sol":209:223  new uint[](10) */
    push(0x40);
    mload();

    dup(1);
    msize();    // Put the size of memory on the stack
    lt();       // less than
    //tag_9
    //jumpi
    if (pop() != 0) goto tag_9;

    pop();
    msize();

    tag_9:
    swap(1);
    dup(1);
    dup(3);
    mstore();
    dup(1);
    push(0x20);
    mul();
    push(0x20);
    add();
    dup(3);
    add();
    push(0x40);
    mstore();
    pop();
    /* "solidity/LocalArrayAccessViolation.sol":191:223  uint[] memory a = new uint[](10) */
    swap(2);
    pop();
    /* "solidity/LocalArrayAccessViolation.sol":308:309  0 */
    push(0x0);
    /* "solidity/LocalArrayAccessViolation.sol":296:309  uint256 i = 0 */
    swap(1);
    pop();

    /* "solidity/LocalArrayAccessViolation.sol":292:369  for(uint256 i = 0; i < value_count; i++) {... */
    tag_11:
    /* "solidity/LocalArrayAccessViolation.sol":315:326  value_count */
    dup(3);
    /* "solidity/LocalArrayAccessViolation.sol":311:312  i */
    dup(2);
    /* "solidity/LocalArrayAccessViolation.sol":311:326  i < value_count */
    lt();
    /* "solidity/LocalArrayAccessViolation.sol":292:369  for(uint256 i = 0; i < value_count; i++) {... */
    iszero();
    //tag_12
    //jumpi
    if (pop() != 0) goto tag_12;

    // ---------------------------------------------------------------------------
    /* "solidity/LocalArrayAccessViolation.sol":354:358  0x01 */
    push(0x1);
    /* "solidity/LocalArrayAccessViolation.sol":347:348  a */
    dup(3);
    /* "solidity/LocalArrayAccessViolation.sol":349:350  i */
    dup(3);
    /* "solidity/LocalArrayAccessViolation.sol":347:351  a[i] */
    dup(2);
    mload();
    dup(2);
    lt();
    iszero();
    iszero();
    //tag_14
    //jumpi
    if (pop() != 0) goto tag_14;

    printf("\nIndex out of bounds detected by solidity!");
    __CPROVER_assert(0, "Memory index out of bounds as detected by solidity");
    return -1;
    //invalid

    tag_14:
    swap(1);
    push(0x20);
    add();
    swap(1);
    push(0x20);
    mul();
    add();
    /* "solidity/LocalArrayAccessViolation.sol":347:358  a[i] = 0x01 */
    dup(2);
    dup(2);
    mstore();

    pop();
    pop();
    // ---------------------------------------------------------------------------

    /* "solidity/LocalArrayAccessViolation.sol":328:331  i++ */
    dup(1);
    dup(1);
    push(0x1);
    add();
    swap(2);
    pop();
    pop();
    /* "solidity/LocalArrayAccessViolation.sol":292:369  for(uint256 i = 0; i < value_count; i++) {... */
    //jump(tag_11)
    goto tag_11;

    tag_12:
    /* "solidity/LocalArrayAccessViolation.sol":67:375  function populate_array(uint256 value_count) public {... */
    pop();
    pop();
    pop();
    //jump	// out
    return 0;

    /* "solidity/LocalArrayAccessViolation.sol":26:377  contract LocalArrayAccessViolation {... */
    tag_7:
    push(0x20);
    mload(0x40);
    swap(1);
    dup(2);
    add();
    push(0x40);
    mstore();
    dup(1);
    push(0x0);
    dup(2);
    mstore();
    pop();
    swap(1);
    //jump	// out
    return 0;
}