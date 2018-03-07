//
// Created by fraser on 14/02/18.
//

/* Initialize the size of memory and storage */
void initialise_memory();

/* Stack operations */
void push(int f);
int pop(void);
void dup(int index);
void swap(int index);
void iszero();
void lt();
void add();
void mul();
void sub();
void sdiv();

/* Addressed volatile memory operations */
void mstore();
void mload();
void msize();

/* Addressed non-volatile memory operations */
void sstore();
void sload();

void revert();