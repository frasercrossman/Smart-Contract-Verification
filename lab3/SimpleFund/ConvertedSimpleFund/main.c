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
    printf("Running simple fund\n");
    printf("Attempting to withdraw funds.\n");
    contract();

    return 0;
}

int call_again() {
    push(0x60);             // Size of memory, in memory (maybe)
    push(0x40);
    mstore();

    // Initialize fund_balance
    /* WHEN CALLING AGAIN, DO NOT RESET THE PERSISTENT STATE!
    push(0x96);
    push(0x0);
    sstore();
     */

    // Initialize stack as it is in Remix
    push(0x3ccfd60b);       // Call data (function signature)
    push(0x54);

    // tag_4:
    // stop

    tag_5:
    /* "solidity/fund_vulnerable_simple.sol":239:249  msg.sender */
    // caller
    // 0xca35b7d915458ef540ade6068dfe2f44e8fa733c
    push(0xca35b7d9); // front of address from Remix above

    /* "solidity/fund_vulnerable_simple.sol":239:254  msg.sender.call */
    push(0xffffffff);//0xffffffffffffffffffffffffffffffffffffffff);
    and();
    /* "solidity/fund_vulnerable_simple.sol":261:273  fund_balance */
    push(0x0);
    sload();
    /* "solidity/fund_vulnerable_simple.sol":239:276  msg.sender.call.value(fund_balance)() */
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
    // sub(gas, 0x8796)
    push(0x2d71d1);         // Value taken from Remix
    push(0x8796);
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

    /* "solidity/fund_vulnerable_simple.sol":235:306  if (msg.sender.call.value(fund_balance)())... */
    iszero();
    // tag_7
    // jumpi
    if (pop() == 0) goto tag_7;

    /* "solidity/fund_vulnerable_simple.sol":305:306  0 */
    push(0x0);
    /* "solidity/fund_vulnerable_simple.sol":290:302  fund_balance */
    dup(1);
    /* "solidity/fund_vulnerable_simple.sol":290:306  fund_balance = 0 */
    dup(2);
    swap(1);
    sstore();
    pop();

    /* "solidity/fund_vulnerable_simple.sol":235:306  if (msg.sender.call.value(fund_balance)())... */
    tag_7:
    /* "solidity/fund_vulnerable_simple.sol":198:313  function withdraw() public {... */
    //jump	// out
    return 0;
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

    // Initialize fund_balance
    push(0x96);
    push(0x0);
    sstore();

    // Initialize stack as it is in Remix
    push(0x3ccfd60b);       // Call data (function signature)
    push(0x54);

    // tag_4:
    // stop

    tag_5:
    /* "solidity/fund_vulnerable_simple.sol":239:249  msg.sender */
    // caller
    // 0xca35b7d915458ef540ade6068dfe2f44e8fa733c
    push(0xca35b7d9); // front of address from Remix above

    /* "solidity/fund_vulnerable_simple.sol":239:254  msg.sender.call */
    push(0xffffffff);//0xffffffffffffffffffffffffffffffffffffffff);
    and();
    /* "solidity/fund_vulnerable_simple.sol":261:273  fund_balance */
    push(0x0);
    sload();
    /* "solidity/fund_vulnerable_simple.sol":239:276  msg.sender.call.value(fund_balance)() */
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
    // sub(gas, 0x8796)
    push(0x2d71d1);         // Value taken from Remix
    push(0x8796);
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

    /* "solidity/fund_vulnerable_simple.sol":235:306  if (msg.sender.call.value(fund_balance)())... */
    iszero();
    // tag_7
    // jumpi
    if (pop() == 0) goto tag_7;

    /* "solidity/fund_vulnerable_simple.sol":305:306  0 */
    push(0x0);
    /* "solidity/fund_vulnerable_simple.sol":290:302  fund_balance */
    dup(1);
    /* "solidity/fund_vulnerable_simple.sol":290:306  fund_balance = 0 */
    dup(2);
    swap(1);
    sstore();
    pop();

    /* "solidity/fund_vulnerable_simple.sol":235:306  if (msg.sender.call.value(fund_balance)())... */
    tag_7:
    /* "solidity/fund_vulnerable_simple.sol":198:313  function withdraw() public {... */
    //jump	// out
    return 0;
}