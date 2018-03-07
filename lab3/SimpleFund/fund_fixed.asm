
======= solidity/fund_fixed.sol:Fund =======
EVM assembly:
    /* "solidity/fund_fixed.sol":26:305  contract Fund {... */
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
        /* "solidity/fund_fixed.sol":26:305  contract Fund {... */
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
        /* "solidity/fund_fixed.sol":161:303  function withdraw() public {... */
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
        /* "solidity/fund_fixed.sol":198:207  var share */
      0x0
        /* "solidity/fund_fixed.sol":210:216  shares */
      dup1
        /* "solidity/fund_fixed.sol":210:228  shares[msg.sender] */
      0x0
        /* "solidity/fund_fixed.sol":217:227  msg.sender */
      caller
        /* "solidity/fund_fixed.sol":210:228  shares[msg.sender] */
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
        /* "solidity/fund_fixed.sol":198:228  var share = shares[msg.sender] */
      swap1
      pop
        /* "solidity/fund_fixed.sol":259:260  0 */
      0x0
        /* "solidity/fund_fixed.sol":238:244  shares */
      dup1
        /* "solidity/fund_fixed.sol":238:256  shares[msg.sender] */
      0x0
        /* "solidity/fund_fixed.sol":245:255  msg.sender */
      caller
        /* "solidity/fund_fixed.sol":238:256  shares[msg.sender] */
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
        /* "solidity/fund_fixed.sol":238:260  shares[msg.sender] = 0 */
      dup2
      swap1
      sstore
      pop
        /* "solidity/fund_fixed.sol":270:280  msg.sender */
      caller
        /* "solidity/fund_fixed.sol":270:289  msg.sender.transfer */
      0xffffffffffffffffffffffffffffffffffffffff
      and
        /* "solidity/fund_fixed.sol":270:296  msg.sender.transfer(share) */
      0x8fc
        /* "solidity/fund_fixed.sol":290:295  share */
      dup3
        /* "solidity/fund_fixed.sol":270:296  msg.sender.transfer(share) */
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
        /* "solidity/fund_fixed.sol":161:303  function withdraw() public {... */
      pop
      jump	// out

    auxdata: 0xa165627a7a7230582081eedbf3f0bc462ad10ef99992d7ff0f2087f14b4793e8b34d78bb7b8883b7dc0029
}

