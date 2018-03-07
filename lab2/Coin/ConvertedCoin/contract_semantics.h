//
// Created by fraser on 14/02/18.
//

/* Stack operations */
extern void push(int f);
extern int pop(void);
extern void dup(int index);
extern void swap(int index);
extern void add();
extern void sub();

/* Addressed volatile memory operations */
extern void mstore(int address, int value);
extern int mload(int address);

/* Addressed non-volatile memory operations */
void sstore(int address, int value);
int sload(int address);

void revert();