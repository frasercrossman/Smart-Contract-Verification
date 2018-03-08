//
// Created by fraser on 08/03/18.
//
#include <stdio.h>
#include "contract_semantics.h"

int contract();
int main() {
    printf("Running Simple Balance\n");
    printf("Attempting to withdraw cash.\n");
    int ret = contract();
    printf("Contract exited with code %d\n", ret);

    return 0;
}

int call_again() {

}

int blank_stack[STACK_SIZE];
int blank_memory[MEMORY_SIZE];
int blank_storage[STORAGE_SIZE];

int contract() {
    // Initialize memory storage and stack
    set_stack(blank_stack);
    set_memory(blank_memory);
    set_storage(blank_storage);


    return 0;
}
