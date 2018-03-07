# SumToN
## ConvertedSumToN
This directory contains all the files developed to emulate the behaviour of the 
contract `sum-to-n.sol` as run by the EVM. `cbmc` was then used to perform 
verification on the contract.
```
$ cbmc main.c contract_semantics.c --signed-overflow-check --trace
...
Violated property:
  file contract_semantics.c line 18 function push
  arithmetic overflow on signed type conversion in (signed char)f
  f >= -128 && !(f >= 128)
...
```

## sum-to-n.c
This file contains code which is a close translation of the contract 
`sum-to-n.sol` to C. `cbmc` was then used to perform verification on the 
program and compared to that produced by the code in `ConvertedSumToN`.
```
$ cbmc sum-to-n.c --signed-overflow-check --trace
...
Violated property:
  file sum-to-n.c line 8 function sum_to_n
  arithmetic overflow on signed type conversion in (signed char)((signed int)s + (signed int)n)
  (signed int)n + (signed int)s >= -128 && !((signed int)n + (signed int)s >= 128)
...
```

## sum-to-n and sum-to-change files
| Filename            | Description |
|---------------------|-------------|
| `sum-to-n.sol`      | Solidity code implementing the sum to n algorithm                   |
| `sum-to-n.asm`      | EVM assembly of the `sum-to-n.sol` contract                         |
| `sum-to-n.op`       | EVM opcodes of the `sum-to-n.sol` contract                          |
| `sum-to-n.op.split` | EVM opcodes of the `sum-to-n.sol` contract split onto separate lines|
---
The sum-to-change files are exactly the same except the code for the sum to n 
algorithm has been removed. This enabled me to quickly identify the compiled 
opcodes of significance by performing a `vimdiff` between the two 
`[contract].op.split` files (The diffs of the two `.asm` files were also used.) 
The `sum-to-n.asm` helped significantly with the translation process as it 
provided addition information such as explicit tag names (rather than 
nondescript `JUMPDEST` opcodes.)

