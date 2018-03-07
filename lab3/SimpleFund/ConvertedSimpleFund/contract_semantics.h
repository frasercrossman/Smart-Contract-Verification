//
// Created by fraser on 14/02/18.
//

#define STACK_SIZE 1024         /* max stack depth */
#define MEMORY_SIZE 512         /* volatile memory size */
#define STORAGE_SIZE 512        /* non-volatile storage size */

/* Stack, memory, and storage */
void init_stack();
void set_stack(int* new_stack);
int* get_stack();
void set_stack_pointer(int new_stack_pointer);
int get_stack_pointer();
void init_memory();
void set_memory(int* new_memory);
int* get_memory();
void set_memory_size(int new_memory_size);
int get_memory_size();
void init_storage();
void set_storage(int* new_storage);
int* get_storage();

/* Stack operations */
void push(int f);
int pop(void);
int peek(int index);
void dup(int index);
void swap(int index);
void iszero();
void lt();
void and();
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

void call();
void revert();
void stack_dump();