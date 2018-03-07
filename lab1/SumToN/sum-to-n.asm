
======= sum-to-n.sol:SumContract =======
EVM assembly:
    /* "sum-to-n.sol":25:309  contract SumContract {... */
  mstore(0x40, 0x60)
    /* "sum-to-n.sol":78:103  function SumContract() {} */
  jumpi(tag_1, iszero(callvalue))
  0x0
  dup1
  revert
tag_1:
    /* "sum-to-n.sol":25:309  contract SumContract {... */
  dataSize(sub_0)
  dup1
  dataOffset(sub_0)
  0x0
  codecopy
  0x0
  return
stop

sub_0: assembly {
        /* "sum-to-n.sol":25:309  contract SumContract {... */
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
        /* "sum-to-n.sol":135:307  function SumToN(int8 N) constant returns (int8 s) {... */
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
        /* "sum-to-n.sol":177:183  int8 s */
      0x0
        /* "sum-to-n.sol":210:216  int8 n */
      dup1
        /* "sum-to-n.sol":199:200  0 */
      0x0
        /* "sum-to-n.sol":195:200  s = 0 */
      swap2
      pop
        /* "sum-to-n.sol":219:220  N */
      dup3
        /* "sum-to-n.sol":210:220  int8 n = N */
      swap1
      pop
        /* "sum-to-n.sol":230:301  while (n > 0) {... */
    tag_7:
        /* "sum-to-n.sol":241:242  0 */
      0x0
        /* "sum-to-n.sol":237:238  n */
      dup2
        /* "sum-to-n.sol":237:242  n > 0 */
      0x0
      signextend
      sgt
        /* "sum-to-n.sol":230:301  while (n > 0) {... */
      iszero
      tag_8
      jumpi
        /* "sum-to-n.sol":266:267  n */
      dup1
        /* "sum-to-n.sol":262:263  s */
      dup3
        /* "sum-to-n.sol":262:267  s + n */
      add
        /* "sum-to-n.sol":258:267  s = s + n */
      swap2
      pop
        /* "sum-to-n.sol":289:290  1 */
      0x1
        /* "sum-to-n.sol":285:286  n */
      dup2
        /* "sum-to-n.sol":285:290  n - 1 */
      sub
        /* "sum-to-n.sol":281:290  n = n - 1 */
      swap1
      pop
        /* "sum-to-n.sol":230:301  while (n > 0) {... */
      jump(tag_7)
    tag_8:
        /* "sum-to-n.sol":135:307  function SumToN(int8 N) constant returns (int8 s) {... */
      pop
      swap2
      swap1
      pop
      jump	// out

    auxdata: 0xa165627a7a7230582088d567281ffbaecb115d653f64e5f7289b01612c0df243d6b78cace4593b1c520029
}

