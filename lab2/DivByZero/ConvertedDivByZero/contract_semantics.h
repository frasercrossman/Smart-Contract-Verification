//
// Created by fraser on 14/02/18.
//

/* Stack operations */
void push(int f);
int pop(void);
void dup(int index);
void swap(int index);
void iszero();
void add();
void sub();
void sdiv();

/* Addressed volatile memory operations */
void mstore(int address, int value);
int mload(int address);

/* Addressed non-volatile memory operations */
void sstore(int address, int value);
int sload(int address);

void revert();