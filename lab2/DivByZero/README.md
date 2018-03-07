# DivByZero
## ConvertedDivByZero
This directory contains all the files developed to emulate the behaviour of the 
contract `div-by-zero.sol` as run by the EVM. `cbmc` was then used to perform 
verification on the contract.
```
$ cbmc main.c contract_semantics.c --div-by-zero-check --trace
...
Violated property:
  file contract_semantics.c line 76 function sdiv
  division by zero in (signed int)return_value_pop$1 / return_value_pop$2
  !(return_value_pop$2 == 0)
...
```

## div-by-zero.c
This file contains code which is a close translation of the contract 
`div-by-zero.sol` to C. `cbmc` was then used to perform verification on the 
program and compared to that produced by the code in `ConvertedDivByZero`.
```
$ cbmc div-by-zero.c --div-by-zero-check --trace
...
Violated property:
  file div-by-zero.c line 5 function div_by_zero
  division by zero in (signed int)numerator / denominator
  !(denominator == 0)
...
```

## div-by-zero files
| Filename            | Description |
|---------------------|-------------|
| `sum-to-n.sol`      | Solidity code implementing a division by a provided value|
| `sum-to-n.asm`      | EVM assembly of the `div-by-zero.sol` contract           |

