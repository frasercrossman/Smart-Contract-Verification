
======= solidity/fund_fixed_simple.sol:Fund =======
EVM assembly:
    /* "solidity/fund_fixed_simple.sol":26:287  contract Fund {... */
  mstore(0x40, 0x60)
    /* "solidity/fund_fixed_simple.sol":115:118  150 */
  0x96
    /* "solidity/fund_fixed_simple.sol":95:118  uint fund_balance = 150 */
  0x0
  sstore
    /* "solidity/fund_fixed_simple.sol":26:287  contract Fund {... */
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
        /* "solidity/fund_fixed_simple.sol":26:287  contract Fund {... */
      mstore(0x40, 0x60)
      jumpi(tag_1, lt(calldatasize, 0x4))
      calldataload(0x0)
      0x100000000000000000000000000000000000000000000000000000000
      swap1
      div
      0xffffffff
      and
      dup1
      0x3ccfd60b
      eq
      tag_2
      jumpi
    tag_1:
      0x0
      dup1
      revert
        /* "solidity/fund_fixed_simple.sol":154:285  function withdraw() public {... */
    tag_2:
      jumpi(tag_3, iszero(callvalue))
      0x0
      dup1
      revert
    tag_3:
      tag_4
      jump(tag_5)
    tag_4:
      stop
    tag_5:
        /* "solidity/fund_fixed_simple.sol":191:201  uint money */
      0x0
        /* "solidity/fund_fixed_simple.sol":204:216  fund_balance */
      dup1
      sload
        /* "solidity/fund_fixed_simple.sol":191:216  uint money = fund_balance */
      swap1
      pop
        /* "solidity/fund_fixed_simple.sol":241:242  0 */
      0x0
        /* "solidity/fund_fixed_simple.sol":226:238  fund_balance */
      dup1
        /* "solidity/fund_fixed_simple.sol":226:242  fund_balance = 0 */
      dup2
      swap1
      sstore
      pop
        /* "solidity/fund_fixed_simple.sol":252:262  msg.sender */
      caller
        /* "solidity/fund_fixed_simple.sol":252:271  msg.sender.transfer */
      0xffffffffffffffffffffffffffffffffffffffff
      and
        /* "solidity/fund_fixed_simple.sol":252:278  msg.sender.transfer(money) */
      0x8fc
        /* "solidity/fund_fixed_simple.sol":272:277  money */
      dup3
        /* "solidity/fund_fixed_simple.sol":252:278  msg.sender.transfer(money) */
      swap1
      dup2
      iszero
      mul
      swap1
      mload(0x40)
      0x0
      mload(0x40)
      dup1
      dup4
      sub
      dup2
      dup6
      dup9
      dup9
      call
      swap4
      pop
      pop
      pop
      pop
      iszero
      iszero
      tag_7
      jumpi
      0x0
      dup1
      revert
    tag_7:
        /* "solidity/fund_fixed_simple.sol":154:285  function withdraw() public {... */
      pop
      jump	// out

    auxdata: 0xa165627a7a723058205843f18bb4e37506a43f931bfccfddbd9e38c306ee4ade771487b2a25833f16e0029
}

