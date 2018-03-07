
======= solidity/DivByZero.sol:DivByZero =======
EVM assembly:
    /* "solidity/DivByZero.sol":26:173  contract DivByZero {... */
  mstore(0x40, 0x60)
  jumpi(tag_1, iszero(callvalue))
  0x0
  dup1
  revert
tag_1:
  dataSize(sub_0)
  dup1
  dataOffset(sub_0)
  0x0
  codecopy
  0x0
  return
stop

sub_0: assembly {
        /* "solidity/DivByZero.sol":26:173  contract DivByZero {... */
      mstore(0x40, 0x60)
      jumpi(tag_1, lt(calldatasize, 0x4))
      calldataload(0x0)
      0x100000000000000000000000000000000000000000000000000000000
      swap1
      div
      0xffffffff
      and
      dup1
      0xf5984236
      eq
      tag_2
      jumpi
    tag_1:
      0x0
      dup1
      revert
        /* "solidity/DivByZero.sol":51:171  function divide(int numerator, int denominator) public pure returns(int) {... */
    tag_2:
      jumpi(tag_3, iszero(callvalue))
      0x0
      dup1
      revert
    tag_3:
      tag_4
      0x4
      dup1
      dup1
      calldataload
      swap1
      0x20
      add
      swap1
      swap2
      swap1
      dup1
      calldataload
      swap1
      0x20
      add
      swap1
      swap2
      swap1
      pop
      pop
      jump(tag_5)
    tag_4:
      mload(0x40)
      dup1
      dup3
      dup2
      mstore
      0x20
      add
      swap2
      pop
      pop
      mload(0x40)
      dup1
      swap2
      sub
      swap1
      return
    tag_5:
        /* "solidity/DivByZero.sol":119:122  int */
      0x0
        /* "solidity/DivByZero.sol":153:164  denominator */
      dup2
        /* "solidity/DivByZero.sol":141:150  numerator */
      dup4
        /* "solidity/DivByZero.sol":141:164  numerator / denominator */
      dup2
      iszero
      iszero
      tag_7
      jumpi
      invalid
    tag_7:
      sdiv
        /* "solidity/DivByZero.sol":134:164  return numerator / denominator */
      swap1
      pop
        /* "solidity/DivByZero.sol":51:171  function divide(int numerator, int denominator) public pure returns(int) {... */
      swap3
      swap2
      pop
      pop
      jump	// out

    auxdata: 0xa165627a7a72305820904e1ae5b32801ff1b39b18d465fe0d5bf94fb1bfd25660f5959f839990606240029
}

