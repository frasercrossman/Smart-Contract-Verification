//
// Created by fraser on 08/03/18.
//
#include <stdio.h>
#include "contract_semantics.h"

int contract();
int main() {
    printf("Running Simple Balance\n");
    printf("Attempting to withdraw cash.\n");
    int ret = contract();
    printf("Contract exited with code %d\n", ret);

    return 0;
}

// Used by contract
int p_stack[STACK_SIZE];
int p_memory[MEMORY_SIZE];
int p_storage[STORAGE_SIZE];
int p_sp = -1;
int p_memory_size = 4;

int p_calldata[4];

// Used by call again
int s_stack[STACK_SIZE];
int s_storage[STORAGE_SIZE];
int s_memory[MEMORY_SIZE];
int s_sp = -1;
int s_memory_size = 4;

int s_calldata[4];


int call_again() {
    // Initialize memory storage and stack
    set_stack(s_stack);
    set_memory(s_memory);
    set_stack_pointer(s_sp);
    set_memory_size(s_memory_size);

    //s_calldata[0] = 0xc0e317fb; // addToBalance()
    //s_calldata[0] = 0xf8b2cb4f; // getBalance(address)
    s_calldata[0] = 0x5fd8c710; // withdrawBalance()
    set_calldata(s_calldata);

    // BIN RUNTIME
    push(0x60);
    push(0x40);
    mstore();
    push(0x04);
    calldatasize();
    lt();
    push(0x0057);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    push(0x00);
    calldataload();
    //push(0x0100000000000000000000000000000000000000000000000000000000);
    //swap(1);
    //div();
    push(0xffffffff);
    and();
    dup(1);
    push(0x5fd8c710);
    eq();
    push(0x005c);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    dup(1);
    push(0xc0e317fb);
    eq();
    push(0x0071);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    dup(1);
    push(0xf8b2cb4f);
    eq();
    push(0x007b);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    tag_0x57:
    push(0x00);
    dup(1);
    return -1; // REVERT
    tag_0x5c:
    callvalue();
    iszero();
    push(0x0067);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    push(0x00);
    dup(1);
    return -1; // REVERT
    tag_0x67:
    push(0x006f);
    push(0x00c8);
    goto resolve_goto; // JUMP
    tag_0x6f:
    return 0; // STOP
    tag_0x71:
    push(0x0079);
    push(0x0183);
    goto resolve_goto; // JUMP
    tag_0x79:
    return 0; // STOP
    tag_0x7b:
    callvalue();
    iszero();
    push(0x0086);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    push(0x00);
    dup(1);
    return -1; // REVERT
    tag_0x86:
    push(0x00b2);
    push(0x04);
    dup(1);
    dup(1);
    calldataload();
    push(0xffffffff);
    and();
    swap(1);
    push(0x20);
    add();
    swap(1);
    swap(2);
    swap(1);
    pop();
    pop();
    push(0x01d1);
    goto resolve_goto; // JUMP
    tag_0xb2:
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
    return 0; // RETURN
    tag_0xc8:
    caller();
    push(0xffffffff);
    and();
    push(0x00);
    dup(1);
    caller();
    push(0xffffffff);
    and();
    push(0xffffffff);
    and();
    dup(2);
    mstore();
    push(0x20);
    add();
    swap(1);
    dup(2);
    mstore();
    push(0x20);
    add();
    push(0x00);
    sha3();
    sload();
    push(0x40);
    mload();
    push(0x00);
    push(0x40);
    mload();
    dup(1);
    dup(4);
    sub();
    dup(2);
    dup(6);
    dup(8);
    gas();

    // CPROVER checks
    __CPROVER_assert(0, "The function is reentrant\n");
    printf("The function is reentrant\n");
    call();

    swap(3);
    pop();
    pop();
    pop();
    iszero();
    iszero();
    push(0x013d);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    push(0x00);
    dup(1);
    return -1; // REVERT
    tag_0x13d:
    push(0x00);
    dup(1);
    push(0x00);
    caller();
    push(0xffffffff);
    and();
    push(0xffffffff);
    and();
    dup(2);
    mstore();
    push(0x20);
    add();
    swap(1);
    dup(2);
    mstore();
    push(0x20);
    add();
    push(0x00);
    sha3();
    dup(2);
    swap(1);
    sstore();
    pop();
    goto resolve_goto; // JUMP
    tag_0x183:
    callvalue();
    push(0x00);
    dup(1);
    caller();
    push(0xffffffff);
    and();
    push(0xffffffff);
    and();
    dup(2);
    mstore();
    push(0x20);
    add();
    swap(1);
    dup(2);
    mstore();
    push(0x20);
    add();
    push(0x00);
    sha3();
    push(0x00);
    dup(3);
    dup(3);
    sload();
    add();
    swap(3);
    pop();
    pop();
    dup(2);
    swap(1);
    sstore();
    pop();
    goto resolve_goto; // JUMP
    tag_0x1d1:
    push(0x00);
    dup(1);
    push(0x00);
    dup(4);
    push(0xffffffff);
    and();
    push(0xffffffff);
    and();
    dup(2);
    mstore();
    push(0x20);
    add();
    swap(1);
    dup(2);
    mstore();
    push(0x20);
    add();
    push(0x00);
    sha3();
    sload();
    swap(1);
    pop();
    swap(2);
    swap(1);
    pop();
    goto resolve_goto; // JUMP

    resolve_goto:
    switch(pop()) {
        case 0x57: goto tag_0x57;
        case 0x5c: goto tag_0x5c;
        case 0x67: goto tag_0x67;
        case 0x6f: goto tag_0x6f;
        case 0x71: goto tag_0x71;
        case 0x79: goto tag_0x79;
        case 0x7b: goto tag_0x7b;
        case 0x86: goto tag_0x86;
        case 0xb2: goto tag_0xb2;
        case 0xc8: goto tag_0xc8;
        case 0x13d: goto tag_0x13d;
        case 0x183: goto tag_0x183;
        case 0x1d1: goto tag_0x1d1;
        default: printf("Invalid JUMP resolved");
    }

    return 0;
}

int contract() {
    // Initialize memory storage and stack
    set_stack(p_stack);
    set_memory(p_memory);
    set_storage(p_storage);
    set_stack_pointer(p_sp);
    set_memory_size(p_memory_size);

    //p_calldata[0] = 0xc0e317fb; // addToBalance()
    //p_calldata[0] = 0xf8b2cb4f; // getBalance(address)
    p_calldata[0] = 0x5fd8c710; // withdrawBalance()
    set_calldata(p_calldata);

    // EVM BOOTSTRAP
    /*
    push(0x60);
    push(0x40);
    mstore();
    push(0x0245);
    dup(1);
    push(0x0013);
    push(0x00);
    codecopy();
    push(0x00);
    return 0; // RETURN
    return 0; // STOP
     */

    // BIN RUNTIME
    push(0x60);
    push(0x40);
    mstore();
    push(0x04);
    calldatasize();
    lt();
    push(0x0057);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    push(0x00);
    calldataload();
    //push(0x0100000000000000000000000000000000000000000000000000000000);
    //swap(1);
    //div();
    push(0xffffffff);
    and();
    dup(1);
    push(0x5fd8c710);
    eq();
    push(0x005c);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    dup(1);
    push(0xc0e317fb);
    eq();
    push(0x0071);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    dup(1);
    push(0xf8b2cb4f);
    eq();
    push(0x007b);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    tag_0x57:
    push(0x00);
    dup(1);
    return -1; // REVERT
    tag_0x5c:
    callvalue();
    iszero();
    push(0x0067);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    push(0x00);
    dup(1);
    return -1; // REVERT
    tag_0x67:
    push(0x006f);
    push(0x00c8);
    goto resolve_goto; // JUMP
    tag_0x6f:
    return 0; // STOP
    tag_0x71:
    push(0x0079);
    push(0x0183);
    goto resolve_goto; // JUMP
    tag_0x79:
    return 0; // STOP
    tag_0x7b:
    callvalue();
    iszero();
    push(0x0086);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    push(0x00);
    dup(1);
    return -1; // REVERT
    tag_0x86:
    push(0x00b2);
    push(0x04);
    dup(1);
    dup(1);
    calldataload();
    push(0xffffffff);
    and();
    swap(1);
    push(0x20);
    add();
    swap(1);
    swap(2);
    swap(1);
    pop();
    pop();
    push(0x01d1);
    goto resolve_goto; // JUMP
    tag_0xb2:
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
    return 0; // RETURN
    tag_0xc8:
    caller();
    push(0xffffffff);
    and();
    push(0x00);
    dup(1);
    caller();
    push(0xffffffff);
    and();
    push(0xffffffff);
    and();
    dup(2);
    mstore();
    push(0x20);
    add();
    swap(1);
    dup(2);
    mstore();
    push(0x20);
    add();
    push(0x00);
    sha3();
    sload();
    push(0x40);
    mload();
    push(0x00);
    push(0x40);
    mload();
    dup(1);
    dup(4);
    sub();
    dup(2);
    dup(6);
    dup(8);
    gas();

    // Save stack pointer and memory size
    p_sp = get_stack_pointer();
    p_memory_size = get_memory_size();

    // Call the contract again to test for reentrancy
    call_again();

    // Restore stack pointer and memory size
    set_stack_pointer(p_sp);
    set_memory_size(p_memory_size);

    // Restore stack and memory
    set_stack(p_stack);
    set_memory(p_memory);

    set_calldata(p_calldata);

    call();

    swap(3);
    pop();
    pop();
    pop();
    iszero();
    iszero();
    push(0x013d);
    if(jumpi() == 0) goto resolve_goto; // JUMPI
    push(0x00);
    dup(1);
    return -1; // REVERT
    tag_0x13d:
    push(0x00);
    dup(1);
    push(0x00);
    caller();
    push(0xffffffff);
    and();
    push(0xffffffff);
    and();
    dup(2);
    mstore();
    push(0x20);
    add();
    swap(1);
    dup(2);
    mstore();
    push(0x20);
    add();
    push(0x00);
    sha3();
    dup(2);
    swap(1);
    sstore();
    pop();
    goto resolve_goto; // JUMP
    tag_0x183:
    callvalue();
    push(0x00);
    dup(1);
    caller();
    push(0xffffffff);
    and();
    push(0xffffffff);
    and();
    dup(2);
    mstore();
    push(0x20);
    add();
    swap(1);
    dup(2);
    mstore();
    push(0x20);
    add();
    push(0x00);
    sha3();
    push(0x00);
    dup(3);
    dup(3);
    sload();
    add();
    swap(3);
    pop();
    pop();
    dup(2);
    swap(1);
    sstore();
    pop();
    goto resolve_goto; // JUMP
    tag_0x1d1:
    push(0x00);
    dup(1);
    push(0x00);
    dup(4);
    push(0xffffffff);
    and();
    push(0xffffffff);
    and();
    dup(2);
    mstore();
    push(0x20);
    add();
    swap(1);
    dup(2);
    mstore();
    push(0x20);
    add();
    push(0x00);
    sha3();
    sload();
    swap(1);
    pop();
    swap(2);
    swap(1);
    pop();
    goto resolve_goto; // JUMP

    resolve_goto:
    switch(pop()) {
        case 0x57: goto tag_0x57;
        case 0x5c: goto tag_0x5c;
        case 0x67: goto tag_0x67;
        case 0x6f: goto tag_0x6f;
        case 0x71: goto tag_0x71;
        case 0x79: goto tag_0x79;
        case 0x7b: goto tag_0x7b;
        case 0x86: goto tag_0x86;
        case 0xb2: goto tag_0xb2;
        case 0xc8: goto tag_0xc8;
        case 0x13d: goto tag_0x13d;
        case 0x183: goto tag_0x183;
        case 0x1d1: goto tag_0x1d1;
        default: printf("Invalid JUMP resolved");
    }

    return 0;
}
