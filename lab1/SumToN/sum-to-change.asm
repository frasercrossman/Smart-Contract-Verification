
======= sum-to-change.sol:SumContract =======
EVM assembly:
    /* "sum-to-change.sol":25:209  contract SumContract {... */
  mstore(0x40, 0x60)
    /* "sum-to-change.sol":78:103  function SumContract() {} */
  jumpi(tag_1, iszero(callvalue))
  0x0
  dup1
  revert
tag_1:
    /* "sum-to-change.sol":25:209  contract SumContract {... */
  dataSize(sub_0)
  dup1
  dataOffset(sub_0)
  0x0
  codecopy
  0x0
  return
stop

sub_0: assembly {
        /* "sum-to-change.sol":25:209  contract SumContract {... */
      mstore(0x40, 0x60)
      jumpi(tag_1, lt(calldatasize, 0x4))
      calldataload(0x0)
      0x100000000000000000000000000000000000000000000000000000000
      swap1
      div
      0xffffffff
      and
      dup1
      0x3f3793bb
      eq
      tag_2
      jumpi
    tag_1:
      0x0
      dup1
      revert
        /* "sum-to-change.sol":135:207  function SumToN(int8 N) constant returns (int8 s) {... */
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
      0x0
      signextend
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
      0x0
      signextend
      0x0
      signextend
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
        /* "sum-to-change.sol":177:183  int8 s */
      0x0
        /* "sum-to-change.sol":199:200  0 */
      dup1
        /* "sum-to-change.sol":195:200  s = 0 */
      swap1
      pop
        /* "sum-to-change.sol":135:207  function SumToN(int8 N) constant returns (int8 s) {... */
      swap2
      swap1
      pop
      jump	// out

    auxdata: 0xa165627a7a723058209a292797cb4a7f8682e2cfadbd09a890f3943aa78f5920f07a8096540b4a53890029
}

