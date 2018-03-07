
======= solidity/LocalArrayAccessViolation.sol:LocalArrayAccessViolation =======
EVM assembly:
    /* "solidity/LocalArrayAccessViolation.sol":26:377  contract LocalArrayAccessViolation {... */
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
        /* "solidity/LocalArrayAccessViolation.sol":26:377  contract LocalArrayAccessViolation {... */
      mstore(0x40, 0x60)
      jumpi(tag_1, lt(calldatasize, 0x4))
      calldataload(0x0)
      0x100000000000000000000000000000000000000000000000000000000
      swap1
      div
      0xffffffff
      and
      dup1
      0x3a079db0
      eq
      tag_2
      jumpi
    tag_1:
      0x0
      dup1
      revert
        /* "solidity/LocalArrayAccessViolation.sol":67:375  function populate_array(uint256 value_count) public {... */
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
      pop
      pop
      jump(tag_5)
    tag_4:
      stop
    tag_5:
        /* "solidity/LocalArrayAccessViolation.sol":191:206  uint[] memory a */
      tag_6
      jump	// in(tag_7)
    tag_6:
        /* "solidity/LocalArrayAccessViolation.sol":296:305  uint256 i */
      0x0
        /* "solidity/LocalArrayAccessViolation.sol":220:222  10 */
      0xa
        /* "solidity/LocalArrayAccessViolation.sol":209:223  new uint[](10) */
      mload(0x40)
      dup1
      msize
      lt
      tag_9
      jumpi
      pop
      msize
    tag_9:
      swap1
      dup1
      dup3
      mstore
      dup1
      0x20
      mul
      0x20
      add
      dup3
      add
      0x40
      mstore
      pop
        /* "solidity/LocalArrayAccessViolation.sol":191:223  uint[] memory a = new uint[](10) */
      swap2
      pop
        /* "solidity/LocalArrayAccessViolation.sol":308:309  0 */
      0x0
        /* "solidity/LocalArrayAccessViolation.sol":296:309  uint256 i = 0 */
      swap1
      pop
        /* "solidity/LocalArrayAccessViolation.sol":292:369  for(uint256 i = 0; i < value_count; i++) {... */
    tag_11:
        /* "solidity/LocalArrayAccessViolation.sol":315:326  value_count */
      dup3
        /* "solidity/LocalArrayAccessViolation.sol":311:312  i */
      dup2
        /* "solidity/LocalArrayAccessViolation.sol":311:326  i < value_count */
      lt
        /* "solidity/LocalArrayAccessViolation.sol":292:369  for(uint256 i = 0; i < value_count; i++) {... */
      iszero
      tag_12
      jumpi
        /* "solidity/LocalArrayAccessViolation.sol":354:358  0x01 */
      0x1
        /* "solidity/LocalArrayAccessViolation.sol":347:348  a */
      dup3
        /* "solidity/LocalArrayAccessViolation.sol":349:350  i */
      dup3
        /* "solidity/LocalArrayAccessViolation.sol":347:351  a[i] */
      dup2
      mload
      dup2
      lt
      iszero
      iszero
      tag_14
      jumpi
      invalid
    tag_14:
      swap1
      0x20
      add
      swap1
      0x20
      mul
      add
        /* "solidity/LocalArrayAccessViolation.sol":347:358  a[i] = 0x01 */
      dup2
      dup2
      mstore
      pop
      pop
        /* "solidity/LocalArrayAccessViolation.sol":328:331  i++ */
      dup1
      dup1
      0x1
      add
      swap2
      pop
      pop
        /* "solidity/LocalArrayAccessViolation.sol":292:369  for(uint256 i = 0; i < value_count; i++) {... */
      jump(tag_11)
    tag_12:
        /* "solidity/LocalArrayAccessViolation.sol":67:375  function populate_array(uint256 value_count) public {... */
      pop
      pop
      pop
      jump	// out
        /* "solidity/LocalArrayAccessViolation.sol":26:377  contract LocalArrayAccessViolation {... */
    tag_7:
      0x20
      mload(0x40)
      swap1
      dup2
      add
      0x40
      mstore
      dup1
      0x0
      dup2
      mstore
      pop
      swap1
      jump	// out

    auxdata: 0xa165627a7a72305820d4db8d062f6a37dd71f24187ad7de0d1e364047883be2a52db03aa421a3ee9f90029
}

