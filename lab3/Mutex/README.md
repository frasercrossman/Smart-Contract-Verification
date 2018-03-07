# Mutex
The typical solution to prevent reentrancy attacks is to use a mutex. In this 
test I was able to verify if I could detect reentrancy. I was not able to which 
indicates that the detection method is working as expected.

## ConvertedMutex
This directory contains all the files developed to emulate the behaviour of the 
contract `fund_vulnerable_simple.sol` as run by the EVM. `cbmc` was then used 
to perform verification on the contract.
```
$ cbmc main.c contract_semantics.c
...
** Results:
[contract.assertion.1] Function is reentrant.
: SUCCESS
[call_again.assertion.1] Money can be drained from the contract!
: SUCCESS
...
```
This message indicates that the function is not reentrant and money cannot be 
drained from the contract.

## mutex files
| Filename    | Description |
|-------------|-------------|
| `mutex.sol` | Solidity code implementing a mutex to prevent reentrancy|
| `mutex.asm` | EVM assembly of the `mutex.sol` contract                |

