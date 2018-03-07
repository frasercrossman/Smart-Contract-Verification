//
// Created by fraser on 14/02/18.
//
#include <stdio.h>
#include <inttypes.h>

#define ARRSIZE(x) (sizeof(x) / sizeof(x[0]))
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

int main() {/*
    for (int i = 0; i < 20; i++) {
        printf("Sum to %4d = %4d\n", i, contract(i));
    }*/
    int8_t result = contract(19);

    return 0;
}

int stack_test() {
    push(0x1);
    push(0x1);
    push(0x1);
    pop();
    pop();
    pop();
    push(0x5);
    dup(1);
    push(0x2);
    swap(2);

    return 1;
}

int contract(int N) {
    // USER INPUT SHOULD COME FROM CALLDATA
    push(N);
    // ---

    tag_5:
    /* "sum-to-n.sol":177:183  int8 s */
    push(0x1);
    /* "sum-to-n.sol":210:216  int8 n */
    dup(1);
    /* "sum-to-n.sol":199:200  0 */
    push(0x0);
    /* "sum-to-n.sol":195:200  s = 0 */
    swap(2);
    pop();
    /* "sum-to-n.sol":219:220  N */
    dup(3);
    /* "sum-to-n.sol":210:220  int8 n = N */
    swap(1);
    pop();

    /* "sum-to-n.sol":230:301  while (n > 0) {... */
    tag_7:

    /* "sum-to-n.sol":241:242  0 */
    push(0x0);
    /* "sum-to-n.sol":237:238  n */
    dup(2);
    /* "sum-to-n.sol":237:242  n > 0 */
    //push(0x0);
    //signextend
    //sgt

    /* "sum-to-n.sol":230:301  while (n > 0) {... */
    //iszero
    //tag_8
    //jumpi
    if(!(pop() > pop())) goto tag_8;

    /* "sum-to-n.sol":266:267  n */
    dup(1);
    /* "sum-to-n.sol":262:263  s */
    dup(3);
    /* "sum-to-n.sol":262:267  s + n */
    add();
    /* "sum-to-n.sol":258:267  s = s + n */
    swap(2);
    pop();
    /* "sum-to-n.sol":289:290  1 */
    push(0x1);
    /* "sum-to-n.sol":285:286  n */
    dup(2);
    /* "sum-to-n.sol":285:290  n - 1 */
    sub();
    /* "sum-to-n.sol":281:290  n = n - 1 */
    swap(1);
    pop();
    goto tag_7;

    tag_8:
    pop(); // ignore n
    return pop(); // return s (i.e. sum)
}