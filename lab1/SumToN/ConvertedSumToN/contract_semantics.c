//
// Created by fraser on 14/02/18.
//
#include <stdio.h>
#include <inttypes.h>

#define MAXVAL 100              /* max stack depth */

int sp = -1;                    /* stack pointer */
int8_t eth_stack[MAXVAL];          /* stack */

int memory[MAXVAL];             /* Addressed volatile memory */
int storage[MAXVAL];            /* Addressed non-volatile memory */

/* push: push f value onto stack */
void push(int f) {
    if (sp < MAXVAL) {
        eth_stack[++sp] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
int pop(void) {
    if (sp > -1) {
        return eth_stack[sp--];
    } else {
        printf("error: stack empty\n");
        return 0;
    }
}

/* dup: duplicate the specified indexed value onto the top of the stack */
void dup(int index) {
    if (index <= (sp + 1)) {
        push(eth_stack[sp + 1 - index]);
    } else {
        printf("error: index %g out of bounds\n", index);
    }
}

/* swap: swap the specified indexed value with the top of the stack */
void swap(int index) {
    int top = eth_stack[sp];

    if (index <= sp) {
        eth_stack[sp] = eth_stack[sp - index];
        eth_stack[sp - index] = top;
    } else {
        printf("error: index %g out of bounds\n", index);
    }
}

/* add: add the top two items on the stack and push the result */
void add() {
    push(pop() + pop());
}

/* sub: subtract the top two items on the stack and push the result */
void sub() {
    push(pop() - pop());
}

/* revert: revert all changes made by the contract */
void revert() {
    printf("revert invoked\n");
}

void mstore(int address, int value) {
    memory[address] = value;
}

int mload(int address) {
    return memory[address];
}

void sstore(int address, int value) {
    storage[address] = value;
}

int sload(int address) {
    return storage[address];
}