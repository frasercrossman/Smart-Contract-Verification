//
// Created by fraser on 14/02/18.
//
#include <stdio.h>
#include <math.h>
#include "contract_semantics.h"

int sp = -1;                    /* Stack pointer */
int* stack = NULL;              /* Stack */

int memory_size = 4;            /* Number of words used in memory - 4 is default on call */
int* memory = NULL;             /* Addressed volatile memory */

int* storage = NULL;            /* Addressed non-volatile storage */

/* init_stack: */
void init_stack() {
    int blank_stack[STACK_SIZE];
    stack = blank_stack;
}

/* set_stack: */
void set_stack(int* new_stack) {
    stack = new_stack;
}

/* get_stack: */
int* get_stack() {
    return stack;
}

/* set_stack_pointer: */
void set_stack_pointer(int new_stack_pointer) {
    sp = new_stack_pointer;
}

/* get_stack_pointer: */
int get_stack_pointer() {
    return sp;
}


/* init_memory: */
void init_memory() {
    int blank_memory[MEMORY_SIZE];
    memory = blank_memory;
}

/* set_memory: */
void set_memory(int* new_memory) {
    memory = new_memory;
}

/* get_memory: */
int* get_memory() {
    return memory;
}

/* set_memory_size: */
void set_memory_size(int new_memory_size) {
    memory_size = new_memory_size;
}

/* get_memory_size: */
int get_memory_size() {
    return memory_size;
}


/* init_storage: */
void init_storage() {
    int blank_storage[STORAGE_SIZE];
    storage = blank_storage;
}

/* set_storage: */
void set_storage(int* new_storage) {
    storage = new_storage;
}

/* get_storage: */
int* get_storage() {
    return storage;
}


/* push: push f value onto stack */
void push(int f) {
    if (sp < STACK_SIZE) {
        stack[++sp] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
int pop(void) {
    if (sp > -1) {
        return stack[sp--];
    } else {
        printf("error: stack empty\n");
        return 0;
    }
}

int peek(int index) {
    // 0 - bottom of stack
    // sp - top of the stack
    return stack[sp - index];
}

/* dup: duplicate the specified indexed value onto the top of the stack */
void dup(int index) {
    if (index <= (sp + 1)) {
        push(stack[sp + 1 - index]);
    } else {
        printf("error: index %g out of bounds\n", index);
    }
}

/* swap: swap the specified indexed value with the top of the stack */
void swap(int index) {
    int top = stack[sp];

    if (index <= sp) {
        stack[sp] = stack[sp - index];
        stack[sp - index] = top;
    } else {
        printf("error: index %g out of bounds\n", index);
    }
}

/* iszero: if the value on the top of the stack is zero push 1, otherwise push 0 */
void iszero() {
    if (pop() == 0) {
        push(1);
    } else {
        push(0);
    }
}

/* lt: if s[0] < s[1] then 1 otherwise 0, where s[n] is a stack value */
void lt() {
    if (pop() < pop()) {
        push(1);
    } else {
        push(0);
    }
}

/* and: and the top two items on the stack and push the result */
void and() {
    push(pop() & pop());
}

/* or: or the top two items on the stack and push the result */
void or() {
    push(pop() | pop());
}

/* not: not the top item on the stack and push the result */
void not() {
    push(~pop());
}

/* add: add the top two items on the stack and push the result */
void add() {
    push(pop() + pop());
}

/* mul: multiply the top two items on the stack and push the result */
void mul() {
    push(pop() * pop());
}

/* sub: subtract the top two items on the stack and push the result */
void sub() {
    push(pop() - pop());
}

/* div: unsigned integer division, push result on the stack */
void div() {
    push((int) pop() / pop());
}

/* sdiv: signed integer division, push result on the stack */
void sdiv() {
    push((int) pop() / pop());
}

/* exp: exponentiation u[0]^u[1] and push the result */
void eth_exp() {
    //push((int) pow((double) pop(), (double) pop()));
}

/* revert: revert all changes made by the contract */
void revert() {
    printf("revert invoked\n");
}

// Note: memory can never be freed - words_in_memory only ever goes up.
void mstore() {
    int address = pop();    // start address of 32 byte segment
    int value = pop();

    // If words in memory limit is larger, expand memory
    // int mem_accessed = (int) ceil((address + 32) / 32);
    int mem_accessed = (address + 32) / 32;

    //printf("mem_accessed: 0x%03x, address: 0x%03x, memory_size: 0x%03x\n",
    //    mem_accessed, address, memory_size);

    if (mem_accessed > memory_size) {
        memory_size = mem_accessed;

        // No reallocation as it makes CBMC slow
        // memory = realloc(memory, memory_size * 32);
    }

    printf("[mstore] addr: 0x%03x -> val: 0x%03x\n", address, value);
    memory[address] = value;
}

void mload() {
    int address = pop();

    printf("[mload] addr: 0x%03x -> val: 0x%03x\n", address, memory[address]);

    push(memory[address]);
}

void msize() {
    push(memory_size * 32);
}

void sstore() {
    int address = pop();    // start address of 32 byte segment
    int value = pop();

    printf("[sstore] addr: 0x%03x -> val: 0x%03x\n", address, value);
    storage[address] = value;
}

void sload() {
    int address = pop();

    printf("[sload] addr: 0x%03x -> val: 0x%03x\n", address, storage[address]);

    push(storage[address]);
}

void call() {
    int gas = pop();        // call param: gas
    int to = pop();         // call param: to
    int value = pop();      // call param: value
    int in_offset = pop();  // call param: in offset
    int in_size = pop();    // call param: in size
    int out_offset = pop(); // call param: out offset
    int out_size = pop();   // call param: out size

    printf("[call] gas: 0x%03x, to: 0x%03x, value: 0x%03x, "
                   "in_offset: 0x%03x, in_size: 0x%03x, out_offset: 0x%03x, out_size: 0x%03x\n",
           gas, to, value, in_offset, in_size, out_offset, out_size);

    push(0x0);              // Successfully executed
}

void stack_dump() {
    printf("Stack dump:\n");
    for (int i = 0; i < sp + 1; i++) {
        printf("0x%03x: 0x%03x\n", i, stack[i]);
    }
}