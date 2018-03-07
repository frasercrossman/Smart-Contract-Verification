//
// Created by fraser on 22/02/18.
//
#include <stdio.h>
#include <inttypes.h>
#include <memory.h>
#include "contract_semantics.h"

int pos = 0;

#define ARRSIZE(x) (sizeof(x) / sizeof(x[0]))
int contract();
int main() {
    printf("Running simple fund nondet param\n");
    printf("Attempting to withdraw funds.\n");
    int ret = contract();
    printf("Contract exited with code %d\n", ret);

    return 0;
}

int call_data_size = 4 + 32;
unsigned char call_data[4 + 32];

int function_sig = 0x2e1a7d4d; // withdraw
int key = nondet_uint(); // param

int call_again() {
    call_data[call_data_size - 1] = nondet_uint();
    //__CPROVER_assume(call_data[call_data_size - 1] > 0 && call_data[call_data_size - 1] < 100);

    // BIN RUNTIME
    push(0x60);
    push(0x40);
    mstore();
    push(0x4);
    push(call_data_size);//calldatasize
    lt();
    push(0x3f);
    if(jumpi() == 0) goto tag_0x3f;
    push(0x0);
    //calldataload
    pop();
    push(function_sig);

    //push(0x10000000);
    //swap(1); // push, swap, div, equivalent to a bit shift (not necessary here)
    //div();
    push(0xffffffff);
    and();
    dup(1);
    push(0x2e1a7d4d);
    eq();
    push(0x44);
    if(jumpi() == 0) goto tag_0x44;

    //jumpdest
    tag_0x3f:
    push(0x0);
    dup(1);
    return -1;//revert

    //jumpdest
    tag_0x44:
    //callvalue
    push(0x0);

    iszero();
    push(0x4e);
    if(jumpi() == 0) goto tag_0x4e;
    push(0x0);
    dup(1);
    return -1;//revert

    //jumpdest
    tag_0x4e:
    push(0x62);
    push(0x4);
    dup(1);
    dup(1);
    //calldataload
    pop();
    push(call_data[call_data_size - 1]);

    swap(1);
    push(0x20);
    add();
    swap(1);
    swap(2);
    swap(1);
    pop();
    pop();
    push(0x64);
    pop(); goto tag_0x64;//jump

    //jumpdest
    tag_0x62:
    return 0;//stop

    //jumpdest
    tag_0x64:
    dup(1);
    push(0x1);
    sload();
    eq();
    iszero();
    push(0xb8);
    if(jumpi() == 0) goto tag_0xb8;
    push(0x1);
    sload();
    push(0x64);
    sub();
    push(0x1);
    dup(2);
    swap(1);
    sstore();
    pop();
    //caller
    push(0x123456);

    push(0xffffffff);
    and();
    push(0x0);
    sload();
    push(0x40);
    mload();
    push(0x0);
    push(0x40);
    mload();
    dup(1);
    dup(4);
    sub();
    dup(2);
    dup(6);
    dup(8);
    push(0x8796);
    //gas
    push(0x800);

    sub();

    // If this point is reached then the function is reentrant
    // First check if value to be sent is zero
    /* gas  to  value   to_offset   to_size out_offset  out_size
     * 0    1   2       3           4       5           6
     */
    __CPROVER_assert(peek(2) == 0, "Money can be drained from the contract!\n");

    // Then indicate that the function is reentrant
    __CPROVER_assert(0, "Function is reentrant.\n");

    printf("Function is reentrant!\n");

    call();                 // Call the other contract

    swap(3);
    pop();
    pop();
    pop();
    iszero();
    push(0xb7);
    if(jumpi() == 0) goto tag_0xb7;
    push(0x0);
    dup(1);
    dup(2);
    swap(1);
    sstore();
    pop();

    //jumpdest
    tag_0xb8:

    //jumpdest
    tag_0xb7:
    pop();
    pop(); goto tag_0x62;//jump
    return 0;//stop
}

int blank_stack[STACK_SIZE];
int blank_memory[MEMORY_SIZE];
int blank_storage[STORAGE_SIZE];

int contract() {
    // Initialize memory storage and stack
    set_stack(blank_stack);
    set_memory(blank_memory);
    set_storage(blank_storage);

    // EVM BOOTSTRAP CODE
    /*
    push(0x60);
    push(0x40);
    mstore();
     Initialize fund_balance
     and
     Initialize key
     */
    push(0x96);
    push(0x0);
    sstore();
    push(0xf);
    push(0x1);
    sstore();/*
    //callvalue
    iszero();
    push(0x19);
    if(jumpi() == 0) goto tag_0x19;
    push(0x0);
    dup(1);
    return -1;//revert

    //jumpdest
    tag_0x19:
    push(0xe7);
    dup(1);
    push(0x27);
    push(0x0);
    //codecopy
    push(0x0);
    return 0;
    return -1;//stop
    */

    // copy function_sig into call_data
    memcpy(&call_data[0], &function_sig, sizeof(int));          // CBMC loops = 4
    // copy parm into call_data (at end)
    memcpy(&call_data[call_data_size - 1], &key, sizeof(int));  // CBMC loops = 4

    // BIN RUNTIME
    push(0x60);
    push(0x40);
    mstore();
    push(0x4);
    push(call_data_size);//calldatasize
    lt();
    push(0x3f);
    if(jumpi() == 0) goto tag_0x3f;
    push(0x0);
    //calldataload
    pop();
    push(function_sig);

    //push(0x10000000);
    //swap(1); // push, swap, div, equivalent to a bit shift (not necessary here)
    //div();
    push(0xffffffff);
    and();
    dup(1);
    push(0x2e1a7d4d);
    eq();
    push(0x44);
    if(jumpi() == 0) goto tag_0x44;

    //jumpdest
    tag_0x3f:
    push(0x0);
    dup(1);
    return -1;//revert

    //jumpdest
    tag_0x44:
    //callvalue
    push(0x0);

    iszero();
    push(0x4e);
    if(jumpi() == 0) goto tag_0x4e;
    push(0x0);
    dup(1);
    return -1;//revert

    //jumpdest
    tag_0x4e:
    push(0x62);
    push(0x4);
    dup(1);
    dup(1);
    //calldataload
    pop();
    push(call_data[call_data_size - 1]);

    swap(1);
    push(0x20);
    add();
    swap(1);
    swap(2);
    swap(1);
    pop();
    pop();
    push(0x64);
    pop(); goto tag_0x64;//jump

    //jumpdest
    tag_0x62:
    return 0;//stop

    //jumpdest
    tag_0x64:
    dup(1);
    push(0x1);
    sload();
    eq();
    iszero();
    push(0xb8);
    if(jumpi() == 0) goto tag_0xb8;
    push(0x1);
    sload();
    push(0x64);
    sub();
    push(0x1);
    dup(2);
    swap(1);
    sstore();
    pop();
    //caller
    push(0x123456);

    push(0xffffffff);
    and();
    push(0x0);
    sload();
    push(0x40);
    mload();
    push(0x0);
    push(0x40);
    mload();
    dup(1);
    dup(4);
    sub();
    dup(2);
    dup(6);
    dup(8);
    push(0x8796);
    //gas
    push(0x800);

    sub();


    // CPROVER CHECKS
    // Re-run contract to see if we can reach this point again!

    // Record current state
    int *c_stack = get_stack();
    int *c_mem = get_memory();
    int *c_store = get_storage();
    int c_sp = get_stack_pointer();
    int c_mem_s = get_memory_size();

    // Set new state
    int n_stack[STACK_SIZE];
    int n_mem[MEMORY_SIZE];
    int n_store[STORAGE_SIZE];
    memcpy(n_store, c_store, STORAGE_SIZE);
    //__CPROVER_array_copy(n_store, c_store); useful?

    set_stack(n_stack);
    set_memory(n_mem);
    set_storage(n_store);
    set_memory_size(4);
    set_stack_pointer(-1);

    // !!! Reproduce contract !!!
    call_again();
    // !!! Reproduce contract !!!

    // Restore state
    set_stack(c_stack);
    set_memory(c_mem);
    set_storage(c_store);
    set_stack_pointer(c_sp);
    set_memory_size(c_mem_s);

    // CPROVER re-run END


    call();                 // Call the other contract

    swap(3);
    pop();
    pop();
    pop();
    iszero();
    push(0xb7);
    if(jumpi() == 0) goto tag_0xb7;
    push(0x0);
    dup(1);
    dup(2);
    swap(1);
    sstore();
    pop();

    //jumpdest
    tag_0xb8:

    //jumpdest
    tag_0xb7:
    pop();
    pop(); goto tag_0x62;//jump
    return 0;//stop
}