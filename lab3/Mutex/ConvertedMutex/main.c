//
// Created by fraser on 22/02/18.
//
#include <stdio.h>
#include <inttypes.h>
#include <memory.h>
#include "contract_semantics.h"

#define ARRSIZE(x) (sizeof(x) / sizeof(x[0]))
int contract();

int main() {
    printf("Running mutex\n");
    printf("Attempting to call non-reentrant function f.\n");
    contract();

    return 0;
}

int call_again() {
    int reentrant = 0;

    push(0x60);             // Size of memory, in memory (maybe)
    push(0x40);
    mstore();

    // Initialize stack as it is in Remix
    push(0x26121ff0);       // Call data (function signature)
    push(0x54);

    tag_3:
    //tag_4
    //jump(tag_5)
    goto tag_5;

    tag_4:
    push(0x40);
    mload();
    dup(1);
    dup(3);
    dup(2);
    mstore();
    push(0x20);
    add();
    swap(2);
    pop();
    pop();
    push(0x40);
    mload();
    dup(1);
    swap(2);
    sub();
    swap(1);
    return 0;

    tag_5:
    /* "solidity/mutex.sol":480:484  uint */
    push(0x0);
    /* "solidity/mutex.sol":81:87  locked */
    dup(1);
    push(0x0);
    swap(1);
    sload();
    swap(1);
    push(0x100);
    //exp - exponentiation
    //eth_exp();
    pop(); pop(); push(0x01);

    swap(1);
    div();
    push(0xff);
    and();
    /* "solidity/mutex.sol":80:87  !locked */
    iszero();
    /* "solidity/mutex.sol":72:88  require(!locked) */
    iszero();
    iszero();
    //tag_7
    //jumpi
    if(pop() != 0) goto tag_7;
    push(0x0);
    dup(1);
    //revert
    return reentrant;

    tag_7:
    /* "solidity/mutex.sol":107:111  true */
    push(0x1);
    /* "solidity/mutex.sol":98:104  locked */
    push(0x0);
    dup(1);
    /* "solidity/mutex.sol":98:111  locked = true */
    push(0x100);
    //exp - exponentiation
    //eth_exp();
    pop(); pop(); push(0x01);

    dup(2);
    sload();
    dup(2);
    push(0xff);
    mul();
    not();
    and();
    swap(1);
    dup(4);
    iszero();
    iszero();
    mul();
    or();
    swap(1);
    sstore();
    pop();
    /* "solidity/mutex.sol":504:514  msg.sender */
    //caller
    // 0xca35b7d915458ef540ade6068dfe2f44e8fa733c
    push(0xca35b7d9); // front of address from Remix above
    /* "solidity/mutex.sol":504:519  msg.sender.call */
    push(0xfffffff);//0xffffffffffffffffffffffffffffffffffffffff
    and();
    /* "solidity/mutex.sol":504:521  msg.sender.call() */
    push(0x40);
    mload();
    push(0x0);
    push(0x40);
    mload();
    dup(1);
    dup(4);
    sub();
    dup(2);
    push(0x0);
    dup(7);
    //sub(gas, 0x646e)
    push(0x2d71d1);         // Value taken from Remix
    push(0x646e);
    sub();

    // If this point is reached then the function is reentrant
    // First check if value to be sent is zero
    /* gas  to  value   to_offset   to_size out_offset  out_size
     * 0    1   2       3           4       5           6
     */
    __CPROVER_assert(peek(2) == 0, "Money can be drained from the contract!\n");
    if(peek(2) == 0) {
        printf("[TEST] Ether drain: SUCCESS, Ether cannot be drained.\n");
    } else {
        printf("[TEST] Ether drain: FAILED, Ether can be drained.\n");
    }

    reentrant = 1;
    call();

    swap(2);
    pop();
    pop();
    /* "solidity/mutex.sol":496:522  require(msg.sender.call()) */
    iszero();
    iszero();
    // tag_9
    // jumpi
    if(pop() != 0) goto tag_9;
    push(0x0);
    dup(1);
    //revert
    return reentrant;

    tag_9:
    /* "solidity/mutex.sol":539:540  7 */
    push(0x7);
    /* "solidity/mutex.sol":532:540  return 7 */
    swap(1);
    pop();
    /* "solidity/mutex.sol":141:146  false */
    push(0x0);
    /* "solidity/mutex.sol":132:138  locked */
    dup(1);
    push(0x0);
    /* "solidity/mutex.sol":132:146  locked = false */
    push(0x100);
    //exp - exponentiation
    //eth_exp();
    pop(); pop(); push(0x01);

    dup(2);
    sload();
    dup(2);
    push(0xff);
    mul();
    not();
    and();
    swap(1);
    dup(4);
    iszero();
    iszero();
    mul();
    or();
    swap(1);
    sstore();
    pop();
    /* "solidity/mutex.sol":438:547  function f() public noReentrancy returns (uint) {... */
    swap(1);
    //jump	// out
    return reentrant;
}

int contract() {
    // Initialize memory storage and stack
    int blank_stack[STACK_SIZE];
    set_stack(blank_stack);
    int blank_memory[MEMORY_SIZE];
    set_memory(blank_memory);
    int blank_storage[STORAGE_SIZE];
    set_storage(blank_storage);

    push(0x60);             // Size of memory, in memory (maybe)
    push(0x40);
    mstore();

    // Initialize stack as it is in Remix
    push(0x26121ff0);       // Call data (function signature)
    push(0x54);

    tag_3:
    //tag_4
    //jump(tag_5)
    goto tag_5;

    tag_4:
    push(0x40);
    mload();
    dup(1);
    dup(3);
    dup(2);
    mstore();
    push(0x20);
    add();
    swap(2);
    pop();
    pop();
    push(0x40);
    mload();
    dup(1);
    swap(2);
    sub();
    swap(1);
    return 0;

    tag_5:
    /* "solidity/mutex.sol":480:484  uint */
    push(0x0);
    /* "solidity/mutex.sol":81:87  locked */
    dup(1);
    push(0x0);
    swap(1);
    sload();
    swap(1);
    push(0x100);
    //exp - exponentiation
    //eth_exp();
    pop(); pop(); push(0x01);

    swap(1);
    div();
    push(0xff);
    and();
    /* "solidity/mutex.sol":80:87  !locked */
    iszero();
    /* "solidity/mutex.sol":72:88  require(!locked) */
    iszero();
    iszero();
    //tag_7
    //jumpi
    if(pop() != 0) goto tag_7;
    push(0x0);
    dup(1);
    //revert
    return -1;

    tag_7:
    /* "solidity/mutex.sol":107:111  true */
    push(0x1);
    /* "solidity/mutex.sol":98:104  locked */
    push(0x0);
    dup(1);
    /* "solidity/mutex.sol":98:111  locked = true */
    push(0x100);
    //exp - exponentiation
    //eth_exp();
    pop(); pop(); push(0x01);

    dup(2);
    sload();
    dup(2);
    push(0xff);
    mul();
    not();
    and();
    swap(1);
    dup(4);
    iszero();
    iszero();
    mul();
    or();
    swap(1);
    sstore();
    pop();
    /* "solidity/mutex.sol":504:514  msg.sender */
    //caller
    // 0xca35b7d915458ef540ade6068dfe2f44e8fa733c
    push(0xca35b7d9); // front of address from Remix above
    /* "solidity/mutex.sol":504:519  msg.sender.call */
    push(0xfffffff);//0xffffffffffffffffffffffffffffffffffffffff
    and();
    /* "solidity/mutex.sol":504:521  msg.sender.call() */
    push(0x40);
    mload();
    push(0x0);
    push(0x40);
    mload();
    dup(1);
    dup(4);
    sub();
    dup(2);
    push(0x0);
    dup(7);
    //sub(gas, 0x646e)
    push(0x2d71d1);         // Value taken from Remix
    push(0x646e);
    sub();

    // CPROVER CHECKS
    // Re-run contract to see if we can reach this point again!

    // Record current state
    int* c_stack = get_stack();
    int* c_mem = get_memory();
    int* c_store = get_storage();
    int c_sp = get_stack_pointer();
    int c_mem_s = get_memory_size();

    // Set new state
    int n_stack[STACK_SIZE];
    int n_mem[MEMORY_SIZE];
    int n_store[STORAGE_SIZE];
    memcpy(n_store, c_store, STORAGE_SIZE);

    set_stack(n_stack);
    set_memory(n_mem);
    set_storage(n_store);
    set_memory_size(4);
    set_stack_pointer(-1);

    // Call the contract again
    int reentrant = call_again();
    // Then indicate that the function is reentrant
    __CPROVER_assert(reentrant != 1, "Function is reentrant.\n");
    if(reentrant == 1) {
        printf("[TEST] Reentrancy: SUCCESS, Reentrancy detected\n");
    } else {
        printf("[TEST] Reentrancy: FAILED, Reentrancy not detected\n");
    }
    // ---

    // Restore state
    set_stack(c_stack);
    set_memory(c_mem);
    set_storage(c_store);
    set_stack_pointer(c_sp);
    set_memory_size(c_mem_s);

    // CPROVER re-run END

    call();

    swap(2);
    pop();
    pop();
    /* "solidity/mutex.sol":496:522  require(msg.sender.call()) */
    iszero();
    iszero();
    // tag_9
    // jumpi
    if(pop() != 0) goto tag_9;
    push(0x0);
    dup(1);
    //revert
    return -1;

    tag_9:
    /* "solidity/mutex.sol":539:540  7 */
    push(0x7);
    /* "solidity/mutex.sol":532:540  return 7 */
    swap(1);
    pop();
    /* "solidity/mutex.sol":141:146  false */
    push(0x0);
    /* "solidity/mutex.sol":132:138  locked */
    dup(1);
    push(0x0);
    /* "solidity/mutex.sol":132:146  locked = false */
    push(0x100);
    //exp - exponentiation
    //eth_exp();
    pop(); pop(); push(0x01);

    dup(2);
    sload();
    dup(2);
    push(0xff);
    mul();
    not();
    and();
    swap(1);
    dup(4);
    iszero();
    iszero();
    mul();
    or();
    swap(1);
    sstore();
    pop();
    /* "solidity/mutex.sol":438:547  function f() public noReentrancy returns (uint) {... */
    swap(1);
    //jump	// out
    return 0;
}
