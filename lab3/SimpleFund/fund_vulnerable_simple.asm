
======= solidity/fund_vulnerable_simple.sol:Fund =======
EVM assembly:
    /* "solidity/fund_vulnerable_simple.sol":70:315  contract Fund {... */
  mstore(0x40, 0x60)
    /* "solidity/fund_vulnerable_simple.sol":159:162  150 */
  0x96
    /* "solidity/fund_vulnerable_simple.sol":139:162  uint fund_balance = 150 */
  0x0
  sstore
    /* "solidity/fund_vulnerable_simple.sol":70:315  contract Fund {... */
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
        /* "solidity/fund_vulnerable_simple.sol":70:315  contract Fund {... */
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
        /* "solidity/fund_vulnerable_simple.sol":198:313  function withdraw() public {... */
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
        /* "solidity/fund_vulnerable_simple.sol":239:249  msg.sender */
      caller
        /* "solidity/fund_vulnerable_simple.sol":239:254  msg.sender.call */
      0xffffffffffffffffffffffffffffffffffffffff
      and
        /* "solidity/fund_vulnerable_simple.sol":261:273  fund_balance */
      sload(0x0)
        /* "solidity/fund_vulnerable_simple.sol":239:276  msg.sender.call.value(fund_balance)() */
      mload(0x40)
      0x0
      mload(0x40)
      dup1
      dup4
      sub
      dup2
      dup6
      dup8
      sub(gas, 0x8796)
      call
      swap3
      pop
      pop
      pop
        /* "solidity/fund_vulnerable_simple.sol":235:306  if (msg.sender.call.value(fund_balance)())... */
      iszero
      tag_7
      jumpi
        /* "solidity/fund_vulnerable_simple.sol":305:306  0 */
      0x0
        /* "solidity/fund_vulnerable_simple.sol":290:302  fund_balance */
      dup1
        /* "solidity/fund_vulnerable_simple.sol":290:306  fund_balance = 0 */
      dup2
      swap1
      sstore
      pop
        /* "solidity/fund_vulnerable_simple.sol":235:306  if (msg.sender.call.value(fund_balance)())... */
    tag_7:
        /* "solidity/fund_vulnerable_simple.sol":198:313  function withdraw() public {... */
      jump	// out

    auxdata: 0xa165627a7a7230582016b80db0ee26ea1d20d89d48ab44153f7ce7e013e9515500a696e4b702aaf78a0029
}

