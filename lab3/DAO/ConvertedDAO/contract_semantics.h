//
// Created by fraser on 08/03/18.
//

#define STACK_SIZE 1024         /* max stack depth */
#define MEMORY_SIZE 512         /* volatile memory size */
#define STORAGE_SIZE 512        /* non-volatile storage size */

// Stack, Memory, and Storage Array Settings
void set_stack(int* new_stack);
void set_memory(int* new_memory);
void set_storage(int* new_storage);
void set_calldata(int* new_calldata);

void set_stack_pointer(int new_stack_pointer);
int get_stack_pointer();

void set_calldata_size(int new_calldata_size);
int get_calldata_size();

void set_memory_size(int new_memory_size);
int get_memory_size();

// 0s: Stop and Arithmetic Operations
void stop();
void add();
void mul();
void sub();
void div();
void sdiv();
void mod();
void smod();
void addmod();
void mulmod();
void EVM_exp();
void signextend();

// 10s: Comparison & Bitwise Logic Operations
void lt();
void gt();
void slt();
void sgt();
void eq();
void iszero();
void and();
void or();
void xor();
void not();
void byte();

// 20s: SHA3
void sha3();

// 30s: Environmental Information
void address();
void balance();
void origin();
void caller();
void callvalue();
void calldataload();
void calldatasize();
void calldatacopy();
void codesize();
void codecopy();
void gasprice();
void extcodesize();
void extcodecopy();

// 40s: Block Information
void blockhash();
void coinbase();
void timestamp();
void number();
void difficulty();
void gaslimit();

// 50s: Stack, Memory, Storage and Flow Operations
int pop();
void mload();
void mstore();
void mstore8();
void sload();
void sstore();
void jump();
int jumpi();
void pc();
void msize();
void gas();
void jumpdest();

// 60s & 70s: Push Operations
void push(int f);
void dup(int index);
void swap(int index);

// a0s: Logging Operations
void EVM_log(int index);

// f0s: System operations
void create();
void call();
void callcode();
// void return();
void delegatecall();
void suicide();

// Verification and Debugging Helper Functions
int peek(int index);
void stack_dump();
