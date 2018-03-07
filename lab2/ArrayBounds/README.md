# ArrayBounds
## ConvertedArrayBounds directories
This directory contains all the files developed to emulate the behaviour of the 
contract `array-bounds.sol` as run by the EVM.

## ConvertedArrayBounds_DynamicRuntimeMemory
In the EVM memory (volatile memory) is unbounded. To simulate this 
appropriately in C we must reallocate the memory assigned for the EVM memory
at runtime using malloc and then when necessary realloc.
This had huge negative performance effects for `cbmc` as it must perform
additional checks on allocated memory while exploring all possible paths of the
program.
For this reason this approach was clearly infeasible for contract verification.
(i.e. too many loop unwindings)

## ConvertedArrayBounds_FixedRuntimeMemory
To aleaviate some of the performance effects of continual reallocation of
memory when necessary I decided to change the code so that the allocation is
performed once at the start of the execution using malloc. This still had a
significant enough effect on performance to make the approach infeasible.
(i.e. too many loop unwindings)

## ConvertedArrayBounds_FixedCompileTimeMemory
By specifying the size of the array in a standard array declaration, rather
rather than a pointer, we can have the memory for the array allocated at
compile time. This alleviated all performance issues caused by `cbmc` having to
check memory continually.
For this reason this approach should be used in the future unless a solution
to this found by other means. Unfortunately this does mean that memory will 
be of a fixed size, however often this is small and known.
Running `cbmc` with this configuration enabled me to detect that a divide by
zero error could occur in the program.
```
$ cbmc main.c contract_semantics.c --trace
...
Violated property:
  file main.c line 115 function contract
  Memory index out of bounds
  0 != 0
...
```
Note: The semantics of the EVM (as defined by the yellow paper) specify that if
division by zero occurs that value 1 should be returned. This is acceptable
however by default no exeception is thrown. The Solidity compiler will however
generate code which checks for this case and will therefore throw an exeception.
Using this we can either, modify the semantics to allow a divide by zero to 
occur or (as I have here) add an assertion into the program in place of the
Solidity generated exeception.

## array-bounds.c
This file contains code which is a close translation of the contract 
`array-bounds.sol` to C. `cbmc` was then used to perform verification on the 
program and compared to that produced by the code in `ConvertedArrayBounds_FixedCompileTimeMemory`.
```
$ cbmc array-bounds.c --bounds-check --trace
...
Violated property:
  file array-bounds.c line 8 function populate_array
  array `a' upper bound in a[(signed long int)i]
  !((signed long int)i >= 10l)
...
```

## array-bounds files
| Filename           | Description |
|--------------------|-------------|
| `array-bounds.sol` | Solidity code fills a array with n values, as specified|
| `array-bounds.asm` | EVM assembly of the `array-bounds.sol` contract        |

