# Coin
## ConvertedCoin
This directory contains all the files developed to emulate the behaviour of the 
contract `coin.sol` as run by the EVM. As indicated by the comment in main.c,
the conversion procedure for this contract was aborted for this lab as I 
realised that it would require the use of a SHA hash function which emulates
the behaviour of that used by the EVM. This additional complexity is beyond the 
scope of this project and should only be returned to if entirely necessary.

## coin and coin-change files
| Filename   | Description |
|------------|-------------|
| `coin.sol` | Solidity code implementing the sum to n algorithm|
| `coin.asm` | EVM assembly of the `sum-to-n.sol` contract      |
---
The coin-change files are exactly the same as coin except the body of the 
functions have been removed. This enabled me to quickly identify the compiled 
assembly of significance by performing a `vimdiff` between the two 
`[contract].asm` files.

## The SHA hash hurdle
A SHA hash function is necessary to appropriately emulate the behaviour of the
contract as executed by the EVM. This is because a mapping is used (much like
a Java HashMap) which requires the use of a hash function to map keys to values.
```solidity
mapping (address => uint) public balances;
```
