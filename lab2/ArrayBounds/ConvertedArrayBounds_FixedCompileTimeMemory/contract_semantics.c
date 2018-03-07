//
// Created by fraser on 14/02/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define STACK_SIZE 1024         /* max stack depth */

int sp = -1;                    /* Stack pointer */
int stack[STACK_SIZE];          /* Stack */

int memory_size = 4;            /* Number of words used in memory */
//unsigned char* memory = NULL;   /* Addressed volatile memory */
unsigned char memory[0x200];    /* Addressed volatile memory */

void initialise_memory() {
    //memory = realloc(memory, memory_size * 32);
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

/* sdiv: signed integer division, push result on the stack */
void sdiv() {
    push((int) pop() / pop());
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

    printf("mem_accessed: 0x%03x, address: 0x%03x, memory_size: 0x%03x\n",
        mem_accessed, address, memory_size);

    if (mem_accessed > memory_size) {
        memory_size = mem_accessed;

        // No reallocation as it makes CBMC slow
        // memory = realloc(memory, memory_size * 32);
    }

    printf("[mstore] addr: 0x%03x -> val: 0x%03x\n", address, value);
    memory[address] = value;
    //memcpy(&memory[address], &value, 32);
}

void mload() {
    int address = pop();

    int value = 0;

    push(memory[address]);

    // note, size should really be 32 however we are using int instead of 256int
    //memcpy(&value, &memory[address], sizeof(int));

    //push(value);
}

void msize() {
    push(memory_size * 32);
}
