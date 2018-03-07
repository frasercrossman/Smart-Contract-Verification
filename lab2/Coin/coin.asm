
======= solidity/coin.sol:Coin =======
EVM assembly:
    /* "solidity/coin.sol":25:885  contract Coin {... */
  mstore(0x40, 0x60)
    /* "solidity/coin.sol":421:480  function Coin() public {... */
  jumpi(tag_1, iszero(callvalue))
  0x0
  dup1
  revert
tag_1:
    /* "solidity/coin.sol":463:473  msg.sender */
  caller
    /* "solidity/coin.sol":454:460  minter */
  0x0
  dup1
    /* "solidity/coin.sol":454:473  minter = msg.sender */
  0x100
  exp
  dup2
  sload
  dup2
  0xffffffffffffffffffffffffffffffffffffffff
  mul
  not
  and
  swap1
  dup4
  0xffffffffffffffffffffffffffffffffffffffff
  and
  mul
  or
  swap1
  sstore
  pop
    /* "solidity/coin.sol":25:885  contract Coin {... */
  dataSize(sub_0)
  dup1
  dataOffset(sub_0)
  0x0
  codecopy
  0x0
  return
stop

sub_0: assembly {
        /* "solidity/coin.sol":25:885  contract Coin {... */
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
        /* "solidity/coin.sol":125:146  address public minter */
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
        /* "solidity/coin.sol":152:193  mapping (address => uint) public balances */
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
        /* "solidity/coin.sol":486:629  function mint(address receiver, uint amount) public {... */
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
        /* "solidity/coin.sol":635:883  function send(address receiver, uint amount) public {... */
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
        /* "solidity/coin.sol":125:146  address public minter */
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
        /* "solidity/coin.sol":152:193  mapping (address => uint) public balances */
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
        /* "solidity/coin.sol":486:629  function mint(address receiver, uint amount) public {... */
    tag_14:
        /* "solidity/coin.sol":566:572  minter */
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
        /* "solidity/coin.sol":552:572  msg.sender != minter */
      0xffffffffffffffffffffffffffffffffffffffff
      and
        /* "solidity/coin.sol":552:562  msg.sender */
      caller
        /* "solidity/coin.sol":552:572  msg.sender != minter */
      0xffffffffffffffffffffffffffffffffffffffff
      and
      eq
      iszero
        /* "solidity/coin.sol":548:581  if (msg.sender != minter) return; */
      iszero
      tag_19
      jumpi
        /* "solidity/coin.sol":574:581  return; */
      jump(tag_18)
        /* "solidity/coin.sol":548:581  if (msg.sender != minter) return; */
    tag_19:
        /* "solidity/coin.sol":616:622  amount */
      dup1
        /* "solidity/coin.sol":594:602  balances */
      0x1
        /* "solidity/coin.sol":594:612  balances[receiver] */
      0x0
        /* "solidity/coin.sol":603:611  receiver */
      dup5
        /* "solidity/coin.sol":594:612  balances[receiver] */
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
      0x0
        /* "solidity/coin.sol":594:622  balances[receiver] += amount */
      dup3
      dup3
      sload
      add
      swap3
      pop
      pop
      dup2
      swap1
      sstore
      pop
        /* "solidity/coin.sol":486:629  function mint(address receiver, uint amount) public {... */
    tag_18:
      pop
      pop
      jump	// out
        /* "solidity/coin.sol":635:883  function send(address receiver, uint amount) public {... */
    tag_17:
        /* "solidity/coin.sol":724:730  amount */
      dup1
        /* "solidity/coin.sol":701:709  balances */
      0x1
        /* "solidity/coin.sol":701:721  balances[msg.sender] */
      0x0
        /* "solidity/coin.sol":710:720  msg.sender */
      caller
        /* "solidity/coin.sol":701:721  balances[msg.sender] */
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
        /* "solidity/coin.sol":701:730  balances[msg.sender] < amount */
      lt
        /* "solidity/coin.sol":697:739  if (balances[msg.sender] < amount) return; */
      iszero
      tag_21
      jumpi
        /* "solidity/coin.sol":732:739  return; */
      jump(tag_20)
        /* "solidity/coin.sol":697:739  if (balances[msg.sender] < amount) return; */
    tag_21:
        /* "solidity/coin.sol":776:782  amount */
      dup1
        /* "solidity/coin.sol":752:760  balances */
      0x1
        /* "solidity/coin.sol":752:772  balances[msg.sender] */
      0x0
        /* "solidity/coin.sol":761:771  msg.sender */
      caller
        /* "solidity/coin.sol":752:772  balances[msg.sender] */
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
      0x0
        /* "solidity/coin.sol":752:782  balances[msg.sender] -= amount */
      dup3
      dup3
      sload
      sub
      swap3
      pop
      pop
      dup2
      swap1
      sstore
      pop
        /* "solidity/coin.sol":818:824  amount */
      dup1
        /* "solidity/coin.sol":796:804  balances */
      0x1
        /* "solidity/coin.sol":796:814  balances[receiver] */
      0x0
        /* "solidity/coin.sol":805:813  receiver */
      dup5
        /* "solidity/coin.sol":796:814  balances[receiver] */
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
      0x0
        /* "solidity/coin.sol":796:824  balances[receiver] += amount */
      dup3
      dup3
      sload
      add
      swap3
      pop
      pop
      dup2
      swap1
      sstore
      pop
        /* "solidity/coin.sol":838:872  Sent(msg.sender, receiver, amount) */
      0x3990db2d31862302a685e8086b5755072a6e2b5b780af1ee81ece35ee3cd3345
        /* "solidity/coin.sol":843:853  msg.sender */
      caller
        /* "solidity/coin.sol":855:863  receiver */
      dup4
        /* "solidity/coin.sol":865:871  amount */
      dup4
        /* "solidity/coin.sol":838:872  Sent(msg.sender, receiver, amount) */
      mload(0x40)
      dup1
      dup5
      0xffffffffffffffffffffffffffffffffffffffff
      and
      0xffffffffffffffffffffffffffffffffffffffff
      and
      dup2
      mstore
      0x20
      add
      dup4
      0xffffffffffffffffffffffffffffffffffffffff
      and
      0xffffffffffffffffffffffffffffffffffffffff
      and
      dup2
      mstore
      0x20
      add
      dup3
      dup2
      mstore
      0x20
      add
      swap4
      pop
      pop
      pop
      pop
      mload(0x40)
      dup1
      swap2
      sub
      swap1
      log1
        /* "solidity/coin.sol":635:883  function send(address receiver, uint amount) public {... */
    tag_20:
      pop
      pop
      jump	// out

    auxdata: 0xa165627a7a7230582012ba006933507dbc4aeca4b39ec244a016c86ac77d599cf3cf5bcc93eedcbd6f0029
}

