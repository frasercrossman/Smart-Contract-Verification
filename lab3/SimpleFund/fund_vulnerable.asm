
======= solidity/fund_vulnerable.sol:Fund =======
EVM assembly:
    /* "solidity/fund_vulnerable.sol":70:334  contract Fund {... */
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
        /* "solidity/fund_vulnerable.sol":70:334  contract Fund {... */
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
        /* "solidity/fund_vulnerable.sol":205:332  function withdraw() public {... */
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
        /* "solidity/fund_vulnerable.sol":246:256  msg.sender */
      caller
        /* "solidity/fund_vulnerable.sol":246:261  msg.sender.call */
      0xffffffffffffffffffffffffffffffffffffffff
      and
        /* "solidity/fund_vulnerable.sol":268:274  shares */
      0x0
        /* "solidity/fund_vulnerable.sol":268:286  shares[msg.sender] */
      dup1
        /* "solidity/fund_vulnerable.sol":275:285  msg.sender */
      caller
        /* "solidity/fund_vulnerable.sol":268:286  shares[msg.sender] */
      0xffffffffffffffffffffffffffffffffffffffff
      and
      0xffffffffffffffffffffffffffffffffffffffff
      and
      dup2
      mstore
      0x20
      add
      swap1
      dup2
      mstore
      0x20
      add
      0x0
      keccak256
      sload
        /* "solidity/fund_vulnerable.sol":246:289  msg.sender.call.value(shares[msg.sender])() */
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
        /* "solidity/fund_vulnerable.sol":242:325  if (msg.sender.call.value(shares[msg.sender])())... */
      iszero
      tag_7
      jumpi
        /* "solidity/fund_vulnerable.sol":324:325  0 */
      0x0
        /* "solidity/fund_vulnerable.sol":303:309  shares */
      dup1
        /* "solidity/fund_vulnerable.sol":303:321  shares[msg.sender] */
      0x0
        /* "solidity/fund_vulnerable.sol":310:320  msg.sender */
      caller
        /* "solidity/fund_vulnerable.sol":303:321  shares[msg.sender] */
      0xffffffffffffffffffffffffffffffffffffffff
      and
      0xffffffffffffffffffffffffffffffffffffffff
      and
      dup2
      mstore
      0x20
      add
      swap1
      dup2
      mstore
      0x20
      add
      0x0
      keccak256
        /* "solidity/fund_vulnerable.sol":303:325  shares[msg.sender] = 0 */
      dup2
      swap1
      sstore
      pop
        /* "solidity/fund_vulnerable.sol":242:325  if (msg.sender.call.value(shares[msg.sender])())... */
    tag_7:
        /* "solidity/fund_vulnerable.sol":205:332  function withdraw() public {... */
      jump	// out

    auxdata: 0xa165627a7a72305820cffb4309e26eaf85bdf25aa00976265ef2e8b9d8befa773e27b218d550aa42e50029
}

