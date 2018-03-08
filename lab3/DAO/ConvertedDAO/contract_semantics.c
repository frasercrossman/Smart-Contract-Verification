//
// Created by fraser on 08/03/18.
//
#include <stdio.h>
#include "contract_semantics.h"

int* stack = NULL;              /* Stack */
int* memory = NULL;             /* Addressed volatile memory */
int* storage = NULL;            /* Addressed non-volatile storage */

int sp = -1;                    /* Stack pointer */
int memory_size = 4;            /* Number of words used in memory - 4 is default on call */

//#if 1
//#define DEBUG(a) printf a
//#else
//#define DEBUG(a) (void)0
//#endif

// Stack, Memory, and Storage Array Settings
void set_stack(int* new_stack) {
    stack = new_stack;
}

void set_memory(int* new_memory) {
    memory = new_memory;
}

void set_storage(int* new_storage) {
    storage = new_storage;
}

void set_stack_pointer(int new_stack_pointer) {
    sp = new_stack_pointer;
}

int get_stack_pointer() {
    return sp;
}

void set_memory_size(int new_memory_size) {
    memory_size = new_memory_size;
}

int get_memory_size() {
    return memory_size;
}

// 0s: Stop and Arithmetic Operations
void stop() {
    // Blank implementation
}

void add() {
    push(pop() + pop());
}

void mul() {
    push(pop() * pop());
}

void sub() {
    push(pop() - pop());
}

void div() {
    push(pop() / pop()); // Warning: same as sdiv
}

void sdiv() {
    push(pop() / pop()); // Warning: same as div
}

void mod() {
    push(pop() % pop()); // Warning: same as smod
}

void smod() {
    push(pop() % pop()); // Warning: same as mod
}

void addmod() {
    push((pop() + pop()) % pop()); // Warning: same as smod
}

void mulmod() {
    push((pop() * pop()) % pop()); // Warning: same as smod
}

void EVM_exp() {
    // Incorrectly implemented
    pop();
    pop();
    push(0x01);
}

void signextend() {
    // Incorrectly implemented
    pop();
    pop();
    push(0x01);
}

// 10s: Comparison & Bitwise Logic Operations
void lt() {
    if (pop() < pop()) { // Warning: same as slt
        push(0x01);
    } else {
        push(0x00);
    }
}

void gt() {
    if (pop() > pop()) { // Warning: same as sgt
        push(0x01);
    } else {
        push(0x00);
    }
}

void slt() {
    if (pop() < pop()) { // Warning: same as lt
        push(0x01);
    } else {
        push(0x00);
    }
}

void sgt() {
    if (pop() > pop()) { // Warning: same as gt
        push(0x01);
    } else {
        push(0x00);
    }
}

void eq() {
    if (pop() == pop()) {
        push(0x01);
    } else {
        push(0x00);
    }
}

void iszero() {
    if (pop() == 0x00) {
        push(0x01);
    } else {
        push(0x00);
    }
}

void and() {
    push(pop() & pop());
}

void or() {
    push(pop() | pop());
}

void xor() {
    push(pop() ^ pop());
}

void not() {
    push(~pop());
}

void byte() {
    // Incorrectly implemented
    pop();
    pop();
    push(0x01);
}

// 20s: SHA3
void sha3() {
    // Incorrectly implemented
    pop();
    pop();
    push(0x01);
}

// 30s: Environmental Information
void address() {
    // Random address used
    push(0x012345);
}

void balance() {
    int address = pop();

    // Random balance used
    push(0x678910);
}

void origin() {
    // Random origin used
    push(0x111213);
}

void caller() {
    // Random caller used
    push(0x141516);
}

void callvalue() {
    // Assume callvalue to be zero
    push(0x00);
}

void calldataload() {
    // Incorrectly implemented
    pop();
    push(0x01);
}

void calldatasize() {
    // Assume calldatasize to be 0x24
    push(0x24);
}

void calldatacopy() {
    // Incorrectly implemented
    pop();
    pop();
    pop();
}

void codesize() {
    // Assume codesize to be 0x64
    push(0x64);
}

void codecopy() {
    // Incorrectly implemented
    pop();
    pop();
    pop();
}

void gasprice() {
    // Assume gasprice to be 0x800
    push(0x800);
}

void extcodesize() {
    // Incorrectly implemented
    pop();
    push(0x01);
}

void extcodecopy() {
    // Incorrectly implemented
    pop();
    pop();
    pop();
    pop();
}

// 40s: Block Information
void blockhash() {
    // Incorrectly implemented
    pop();
    push(0x01);
}

void coinbase() {
    // Assume coinbase (block's beneficiary address) to be 0x0666
    push(0x0666);
}

void timestamp() {
    // Assume timestamp to be 0x0765
    push(0x0765);
}

void number() {
    // Assume number (block's number) to be 0x0345
    push(0x0345);
}

void difficulty() {
    // Assume difficulty (block's difficulty) to be 0x0987
    push(0x0987);
}

void gaslimit() {
    // Assume gaslimit (block's gaslimit) to be 0x0135
    push(0x0135);
}

// 50s: Stack, Memory, Storage and Flow Operations
int pop() {
    if (sp > -1) {
        return stack[sp--];
    } else {
        printf("error: stack empty\n");
        return 0;
    }
}

void mload() {
    int address = pop();

    printf("[mload] addr: 0x%03x -> val: 0x%03x\n", address, memory[address]);

    push(memory[address]);
}

void mstore() {
    int address = pop();    // start address of 32 byte segment
    int value = pop();

    int mem_accessed = (address + 32) / 32;

    if (mem_accessed > memory_size) {
        memory_size = mem_accessed;
    }

    printf("[mstore] addr: 0x%03x -> val: 0x%03x\n", address, value);

    memory[address] = value;
}

void mstore8() {
    int address = pop();    // start address of 32 byte segment
    int value = pop() % 256;

    int mem_accessed = (address + 32) / 32;

    if (mem_accessed > memory_size) {
        memory_size = mem_accessed;
    }

    printf("[mstore8] addr: 0x%03x -> val: 0x%03x\n", address, value);

    memory[address] = value;
}

void sload() {
    int address = pop();

    printf("[sload] addr: 0x%03x -> val: 0x%03x\n", address, storage[address]);

    push(storage[address]);
}

void sstore() {
    int address = pop();    // start address of 32 byte segment
    int value = pop();

    printf("[sstore] addr: 0x%03x -> val: 0x%03x\n", address, value);

    storage[address] = value;
}

void jump() {
    // Should never be called as goto is used
}

int jumpi() {
    int jump_pos = pop();
    int condition = pop();

    if (condition != 0) {
        // put the jump position back on the stack to be processed
        push(jump_pos);
        return 0;
    } else {
        return 1;
    }
}

void pc() {
    // Assume pc (program counter) to be 0x0500
    push(0x0500);
}

void msize() {
    push(memory_size * 32);
}

void gas() {
    // Assume gas (gas remaining) to be 0x0700
    push(0x0700);
}

void jumpdest() {
    // Should never be called as tags are used
}

// 60s & 70s: Push Operations
void push(int f) {
    if (sp < STACK_SIZE) {
        stack[++sp] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

void dup(int index) {
    if (index <= (sp + 1)) {
        push(stack[sp + 1 - index]);
    } else {
        printf("error: index %g out of bounds\n", index);
    }
}

void swap(int index) {
    int top = stack[sp];

    if (index <= sp) {
        stack[sp] = stack[sp - index];
        stack[sp - index] = top;
    } else {
        printf("error: index %g out of bounds\n", index);
    }
}

// a0s: Logging Operations
void EVM_log(int index) {
    // Incorrectly implemented
    pop();
    pop();
    for(int i = 0; i < index; i++) {
        pop();
    }
}

// f0s: System operations
void create() {
    int value = pop();        // create param: value
    int in_offset = pop();    // create param: input offset
    int out_offset = pop();   // create param: output offset

    printf("[create] value: 0x%03x, in_offset: 0x%03x, out_offset: 0x%03x\n",
           value, in_offset, out_offset);

    push(0x0);              // Successfully executed
}

void call() {
    int gas = pop();        // call param: gas
    int to = pop();         // call param: to
    int value = pop();      // call param: value
    int in_offset = pop();  // call param: input offset
    int in_size = pop();    // call param: input size
    int out_offset = pop(); // call param: output offset
    int out_size = pop();   // call param: output size

    printf("[call] gas: 0x%03x, to: 0x%03x, value: 0x%03x, "
                   "in_offset: 0x%03x, in_size: 0x%03x, out_offset: 0x%03x, out_size: 0x%03x\n",
           gas, to, value, in_offset, in_size, out_offset, out_size);

    push(0x0);              // Successfully executed
}

void callcode() {
    /*
     * Exactly equivalent to CALL except:
     * Note the change in the fourth parameter to the call Θ from the 2nd stack value µs[1]
     * (as in CALL) to the present address Ia. This means that the recipient is in fact the
     * same account as at present, simply that the code is overwritten.
     */

    int gas = pop();        // callcode param: gas
    int to = pop();         // callcode param: to
    int value = pop();      // callcode param: value
    int in_offset = pop();  // callcode param: input offset
    int in_size = pop();    // callcode param: input size
    int out_offset = pop(); // callcode param: output offset
    int out_size = pop();   // callcode param: output size

    printf("[callcode] gas: 0x%03x, to: 0x%03x, value: 0x%03x, "
                   "in_offset: 0x%03x, in_size: 0x%03x, out_offset: 0x%03x, out_size: 0x%03x\n",
           gas, to, value, in_offset, in_size, out_offset, out_size);

    push(0x0);              // Successfully executed
}

/* This function cannot be implemented as return is a C keyword
 * It should never be called however as return 0; is used instead
void return() {
    pop();
    pop();
}*/

void delegatecall() {
    /*
     * Compared with CALL, DELEGATECALL takes one fewer arguments.
     * The omitted argument is µs [2] (value).
     * Otherwise exactly equivalent to CALL except:
     * Note the changes (in addition to that of the fourth parameter) to the second and
     * ninth parameters to the call (theta). This means that the recipient is in fact the same
     * account as at present, simply that the code is overwritten and the context is
     * almost entirely identical.
     */

    int gas = pop();        // delegatecall param: gas
    int to = pop();         // delegatecall param: to
    int in_offset = pop();  // delegatecall param: input offset
    int in_size = pop();    // delegatecall param: input size
    int out_offset = pop(); // delegatecall param: output offset
    int out_size = pop();   // delegatecall param: output size

    printf("[delegatecall] gas: 0x%03x, to: 0x%03x, "
                   "in_offset: 0x%03x, in_size: 0x%03x, out_offset: 0x%03x, out_size: 0x%03x\n",
           gas, to, in_offset, in_size, out_offset, out_size);

    push(0x0);              // Successfully executed
}

void suicide() {
    // Halt execution and register account for later deletion.
    pop();
}

// Verification and Debugging Helper Functions
int peek(int index) {
    // 0 - bottom of stack
    // sp - top of the stack
    return stack[sp - index];
}

void stack_dump() {
    printf("Stack dump:\n");
    for (int i = 0; i < sp + 1; i++) {
        printf("0x%03x: 0x%03x\n", i, stack[i]);
    }
}
