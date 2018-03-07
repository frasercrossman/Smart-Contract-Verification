# SimpleFundNonDet
## ConvertedSimpleFundNonDet
This directory contains all the files developed to emulate the behaviour of the 
contract `fund_key` as run by the EVM. `cbmc` was then used to perform 
verification on the contract. The `withdraw` function requires that a key be
provided to enable funds to be withdrawn. Initially the key is 15 but then
on calling the function again this changes to 85. For an attacker to exploit 
this contract they must initially make a request with the parameter 15 and then,
in the fallback function of their exploit contract, request with 85.
Previously I have only required that either no parameters are provided or the
parameters remain the same. Here I generate two nondeterministic integers on
each call using `cbmc`. The reentrancy is successfully detected.
```
$ cbmc main.c contract_semantics.c
...
** Results:
[call_again.assertion.1] Money can be drained from the contract!
: FAILURE
[call_again.assertion.2] Function is reentrant.
: FAILURE
...
```
This message indicates that the function is reentrant and money can be drained 
from the contract.

## fund_key files
| Filename       | Description |
|----------------|-------------|
| `fund_key.sol` | Solidity code implementing a fund with a key|
| `fund_key.asm` | EVM assembly of the `fund_key.sol`contract  |


