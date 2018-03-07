
======= solidity/coin_change.sol:Coin =======
EVM assembly:
    /* "solidity/coin_change.sol":25:583  contract Coin {... */
  mstore(0x40, 0x60)
    /* "solidity/coin_change.sol":421:451  function Coin() public {... */
  jumpi(tag_1, iszero(callvalue))
  0x0
  dup1
  revert
tag_1:
    /* "solidity/coin_change.sol":25:583  contract Coin {... */
  dataSize(sub_0)
  dup1
  dataOffset(sub_0)
  0x0
  codecopy
  0x0
  return
stop

sub_0: assembly {
        /* "solidity/coin_change.sol":25:583  contract Coin {... */
      mstore(0x40, 0x60)
      jumpi(tag_1, lt(calldatasize, 0x4))
      calldataload(0x0)
      0x100000000000000000000000000000000000000000000000000000000
      swap1
      div
      0xffffffff
      and
      dup1
      0x7546172
      eq
      tag_2
      jumpi
      dup1
      0x27e235e3
      eq
      tag_3
      jumpi
      dup1
      0x40c10f19
      eq
      tag_4
      jumpi
      dup1
      0xd0679d34
      eq
      tag_5
      jumpi
    tag_1:
      0x0
      dup1
      revert
        /* "solidity/coin_change.sol":125:146  address public minter */
    tag_2:
      jumpi(tag_6, iszero(callvalue))
      0x0
      dup1
      revert
    tag_6:
      tag_7
      jump(tag_8)
    tag_7:
      mload(0x40)
      dup1
      dup3
      0xffffffffffffffffffffffffffffffffffffffff
      and
      0xffffffffffffffffffffffffffffffffffffffff
      and
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
        /* "solidity/coin_change.sol":152:193  mapping (address => uint) public balances */
    tag_3:
      jumpi(tag_9, iszero(callvalue))
      0x0
      dup1
      revert
    tag_9:
      tag_10
      0x4
      dup1
      dup1
      calldataload
      0xffffffffffffffffffffffffffffffffffffffff
      and
      swap1
      0x20
      add
      swap1
      swap2
      swap1
      pop
      pop
      jump(tag_11)
    tag_10:
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
        /* "solidity/coin_change.sol":457:516  function mint(address receiver, uint amount) public {... */
    tag_4:
      jumpi(tag_12, iszero(callvalue))
      0x0
      dup1
      revert
    tag_12:
      tag_13
      0x4
      dup1
      dup1
      calldataload
      0xffffffffffffffffffffffffffffffffffffffff
      and
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
      jump(tag_14)
    tag_13:
      stop
        /* "solidity/coin_change.sol":522:581  function send(address receiver, uint amount) public {... */
    tag_5:
      jumpi(tag_15, iszero(callvalue))
      0x0
      dup1
      revert
    tag_15:
      tag_16
      0x4
      dup1
      dup1
      calldataload
      0xffffffffffffffffffffffffffffffffffffffff
      and
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
      jump(tag_17)
    tag_16:
      stop
        /* "solidity/coin_change.sol":125:146  address public minter */
    tag_8:
      0x0
      dup1
      swap1
      sload
      swap1
      0x100
      exp
      swap1
      div
      0xffffffffffffffffffffffffffffffffffffffff
      and
      dup2
      jump	// out
        /* "solidity/coin_change.sol":152:193  mapping (address => uint) public balances */
    tag_11:
      mstore(0x20, 0x1)
      dup1
      0x0
      mstore
      keccak256(0x0, 0x40)
      0x0
      swap2
      pop
      swap1
      pop
      sload
      dup2
      jump	// out
        /* "solidity/coin_change.sol":457:516  function mint(address receiver, uint amount) public {... */
    tag_14:
      pop
      pop
      jump	// out
        /* "solidity/coin_change.sol":522:581  function send(address receiver, uint amount) public {... */
    tag_17:
      pop
      pop
      jump	// out

    auxdata: 0xa165627a7a7230582089c30671af426a600935dd076e065a6da3efd9a0a3eb093c9968d2584a06499b0029
}

