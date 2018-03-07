
======= fund_key.sol:Fund =======
EVM assembly:
    /* "fund_key.sol":70:452  contract Fund {... */
  mstore(0x40, 0x60)
    /* "fund_key.sol":159:162  150 */
  0x96
    /* "fund_key.sol":139:162  uint fund_balance = 150 */
  0x0
  sstore
    /* "fund_key.sol":179:181  15 */
  0xf
    /* "fund_key.sol":168:181  uint key = 15 */
  0x1
  sstore
    /* "fund_key.sol":70:452  contract Fund {... */
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
        /* "fund_key.sol":70:452  contract Fund {... */
      mstore(0x40, 0x60)
      jumpi(tag_1, lt(calldatasize, 0x4))
      calldataload(0x0)
      0x100000000000000000000000000000000000000000000000000000000
      swap1
      div
      0xffffffff
      and
      dup1
      0x2e1a7d4d
      eq
      tag_2
      jumpi
    tag_1:
      0x0
      dup1
      revert
        /* "fund_key.sol":217:450  function withdraw(uint key_guess) public {... */
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
        /* "fund_key.sol":279:288  key_guess */
      dup1
        /* "fund_key.sol":272:275  key */
      sload(0x1)
        /* "fund_key.sol":272:288  key == key_guess */
      eq
        /* "fund_key.sol":268:444  if (key == key_guess) {... */
      iszero
      tag_7
      jumpi
        /* "fund_key.sol":316:319  key */
      sload(0x1)
        /* "fund_key.sol":310:313  100 */
      0x64
        /* "fund_key.sol":310:319  100 - key */
      sub
        /* "fund_key.sol":304:307  key */
      0x1
        /* "fund_key.sol":304:319  key = 100 - key */
      dup2
      swap1
      sstore
      pop
        /* "fund_key.sol":346:356  msg.sender */
      caller
        /* "fund_key.sol":346:361  msg.sender.call */
      0xffffffffffffffffffffffffffffffffffffffff
      and
        /* "fund_key.sol":368:380  fund_balance */
      sload(0x0)
        /* "fund_key.sol":346:383  msg.sender.call.value(fund_balance)() */
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
        /* "fund_key.sol":342:434  if (msg.sender.call.value(fund_balance)()) {... */
      iszero
      tag_8
      jumpi
        /* "fund_key.sol":418:419  0 */
      0x0
        /* "fund_key.sol":403:415  fund_balance */
      dup1
        /* "fund_key.sol":403:419  fund_balance = 0 */
      dup2
      swap1
      sstore
      pop
        /* "fund_key.sol":342:434  if (msg.sender.call.value(fund_balance)()) {... */
    tag_8:
        /* "fund_key.sol":268:444  if (key == key_guess) {... */
    tag_7:
        /* "fund_key.sol":217:450  function withdraw(uint key_guess) public {... */
      pop
      jump	// out

    auxdata: 0xa165627a7a72305820e56ce5f36e1322a44e83b080a9cdbf247c6de9e23bea019a6aca2f4e6cc1cb170029
}

