
======= solidity/mutex.sol:Mutex =======
EVM assembly:
    /* "solidity/mutex.sol":0:549  contract Mutex {... */
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
        /* "solidity/mutex.sol":0:549  contract Mutex {... */
      mstore(0x40, 0x60)
      jumpi(tag_1, lt(calldatasize, 0x4))
      calldataload(0x0)
      0x100000000000000000000000000000000000000000000000000000000
      swap1
      div
      0xffffffff
      and
      dup1
      0x26121ff0
      eq
      tag_2
      jumpi
    tag_1:
      0x0
      dup1
      revert
        /* "solidity/mutex.sol":438:547  function f() public noReentrancy returns (uint) {... */
    tag_2:
      jumpi(tag_3, iszero(callvalue))
      0x0
      dup1
      revert
    tag_3:
      tag_4
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
        /* "solidity/mutex.sol":480:484  uint */
      0x0
        /* "solidity/mutex.sol":81:87  locked */
      dup1
      0x0
      swap1
      sload
      swap1
      0x100
      exp
      swap1
      div
      0xff
      and
        /* "solidity/mutex.sol":80:87  !locked */
      iszero
        /* "solidity/mutex.sol":72:88  require(!locked) */
      iszero
      iszero
      tag_7
      jumpi
      0x0
      dup1
      revert
    tag_7:
        /* "solidity/mutex.sol":107:111  true */
      0x1
        /* "solidity/mutex.sol":98:104  locked */
      0x0
      dup1
        /* "solidity/mutex.sol":98:111  locked = true */
      0x100
      exp
      dup2
      sload
      dup2
      0xff
      mul
      not
      and
      swap1
      dup4
      iszero
      iszero
      mul
      or
      swap1
      sstore
      pop
        /* "solidity/mutex.sol":504:514  msg.sender */
      caller
        /* "solidity/mutex.sol":504:519  msg.sender.call */
      0xffffffffffffffffffffffffffffffffffffffff
      and
        /* "solidity/mutex.sol":504:521  msg.sender.call() */
      mload(0x40)
      0x0
      mload(0x40)
      dup1
      dup4
      sub
      dup2
      0x0
      dup7
      sub(gas, 0x646e)
      call
      swap2
      pop
      pop
        /* "solidity/mutex.sol":496:522  require(msg.sender.call()) */
      iszero
      iszero
      tag_9
      jumpi
      0x0
      dup1
      revert
    tag_9:
        /* "solidity/mutex.sol":539:540  7 */
      0x7
        /* "solidity/mutex.sol":532:540  return 7 */
      swap1
      pop
        /* "solidity/mutex.sol":141:146  false */
      0x0
        /* "solidity/mutex.sol":132:138  locked */
      dup1
      0x0
        /* "solidity/mutex.sol":132:146  locked = false */
      0x100
      exp
      dup2
      sload
      dup2
      0xff
      mul
      not
      and
      swap1
      dup4
      iszero
      iszero
      mul
      or
      swap1
      sstore
      pop
        /* "solidity/mutex.sol":438:547  function f() public noReentrancy returns (uint) {... */
      swap1
      jump	// out

    auxdata: 0xa165627a7a72305820633e86cd68388887fa4708b03890e2fda764276fc816fec081e83b0fcf3c5d6a0029
}

