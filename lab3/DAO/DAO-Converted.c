push(0x60);
push(0x40);
mstore();
push(0x40);
mload();
push(0x40);
dup(1);
push(0x036a);
dup(4);
codecopy();
dup(2);
add();
push(0x40);
mstore();
dup(1);
dup(1);
mload();
swap(1);
push(0x20);
add();
swap(1);
swap(2);
swap(1);
dup(1);
mload();
swap(1);
push(0x20);
add();
swap(1);
swap(2);
swap(1);
pop();
pop();
tag_0x2a:
dup(2);
push(0x00);
push(0x00);
push(0x0100);
EVM_exp();
dup(2);
sload();
dup(2);
push(0xffffffffffffffffffffffffffffffffffffffff);
mul();
not();
and();
swap(1);
dup(4);
mul();
or();
swap(1);
sstore();
pop();
dup(1);
push(0x00);
push(0x14);
push(0x0100);
EVM_exp();
dup(2);
sload();
dup(2);
push(0xff);
mul();
not();
and();
swap(1);
dup(4);
mul();
or();
swap(1);
sstore();
pop();
tag_0x6e:
pop();
pop();
push(0x02ec);
dup(1);
push(0x007e);
push(0x00);
codecopy();
push(0x00);
return 0; // RETURN
push(0x60);
push(0x40);
mstore();
calldatasize();
iszero();
push(0x005e);
if(jumpi() == 0) goto resolve_goto; // JUMPI
push(0x00);
calldataload();
push(0x0100000000000000000000000000000000000000000000000000000000);
swap(1);
div();
dup(1);
push(0x0221038a);
eq();
push(0x0079);
if(jumpi() == 0) goto resolve_goto; // JUMPI
dup(1);
push(0x18bdc79a);
eq();
push(0x00ae);
if(jumpi() == 0) goto resolve_goto; // JUMPI
dup(1);
push(0x8da5cb5b);
eq();
push(0x00d1);
if(jumpi() == 0) goto resolve_goto; // JUMPI
dup(1);
push(0xd2cc718f);
eq();
push(0x010a);
if(jumpi() == 0) goto resolve_goto; // JUMPI
push(0x005e);
goto resolve_goto; // JUMP
tag_0x5e:
push(0x0077);
tag_0x62:
callvalue();
push(0x01);
push(0x00);
dup(3);
dup(3);
dup(3);
pop();
sload();
add();
swap(3);
pop();
pop();
dup(2);
swap(1);
sstore();
pop();
tag_0x75:
goto resolve_goto; // JUMP
tag_0x77:
return 0; // STOP
tag_0x79:
push(0x0098);
push(0x04);
dup(1);
dup(1);
calldataload();
swap(1);
push(0x20);
add();
swap(1);
swap(2);
swap(1);
dup(1);
calldataload();
swap(1);
push(0x20);
add();
swap(1);
swap(2);
swap(1);
pop();
pop();
push(0x016f);
goto resolve_goto; // JUMP
tag_0x98:
push(0x40);
mload();
dup(1);
dup(3);
dup(2);
mstore();
push(0x20);
add();
swap(2);
pop();
pop();
push(0x40);
mload();
dup(1);
swap(2);
sub();
swap(1);
return 0; // RETURN
tag_0xae:
push(0x00bb);
push(0x04);
dup(1);
pop();
pop();
push(0x0153);
goto resolve_goto; // JUMP
tag_0xbb:
push(0x40);
mload();
dup(1);
dup(3);
dup(2);
mstore();
push(0x20);
add();
swap(2);
pop();
pop();
push(0x40);
mload();
dup(1);
swap(2);
sub();
swap(1);
return 0; // RETURN
tag_0xd1:
push(0x00de);
push(0x04);
dup(1);
pop();
pop();
push(0x012d);
goto resolve_goto; // JUMP
tag_0xde:
push(0x40);
mload();
dup(1);
dup(3);
push(0xffffffffffffffffffffffffffffffffffffffff);
and();
dup(2);
mstore();
push(0x20);
add();
swap(2);
pop();
pop();
push(0x40);
mload();
dup(1);
swap(2);
sub();
swap(1);
return 0; // RETURN
tag_0x10a:
push(0x0117);
push(0x04);
dup(1);
pop();
pop();
push(0x0166);
goto resolve_goto; // JUMP
tag_0x117:
push(0x40);
mload();
dup(1);
dup(3);
dup(2);
mstore();
push(0x20);
add();
swap(2);
pop();
pop();
push(0x40);
mload();
dup(1);
swap(2);
sub();
swap(1);
return 0; // RETURN
tag_0x12d:
push(0x00);
push(0x00);
swap(1);
sload();
swap(1);
push(0x0100);
EVM_exp();
swap(1);
div();
push(0xffffffffffffffffffffffffffffffffffffffff);
and();
dup(2);
goto resolve_goto; // JUMP
tag_0x153:
push(0x00);
push(0x14);
swap(1);
sload();
swap(1);
push(0x0100);
EVM_exp();
swap(1);
div();
push(0xff);
and();
dup(2);
goto resolve_goto; // JUMP
tag_0x166:
push(0x01);
push(0x00);
pop();
sload();
dup(2);
goto resolve_goto; // JUMP
tag_0x16f:
push(0x00);
push(0x00);
push(0x00);
swap(1);
sload();
swap(1);
push(0x0100);
EVM_exp();
swap(1);
div();
push(0xffffffffffffffffffffffffffffffffffffffff);
and();
push(0xffffffffffffffffffffffffffffffffffffffff);
and();
caller();
push(0xffffffffffffffffffffffffffffffffffffffff);
and();
eq();
iszero();
dup(1);
push(0x01ce);
if(jumpi() == 0) goto resolve_goto; // JUMPI
pop();
push(0x00);
callvalue();
gt();
tag_0x1ce:
dup(1);
push(0x023f);
if(jumpi() == 0) goto resolve_goto; // JUMPI
pop();
push(0x00);
push(0x14);
swap(1);
sload();
swap(1);
push(0x0100);
EVM_exp();
swap(1);
div();
push(0xff);
and();
dup(1);
iszero();
push(0x023e);
if(jumpi() == 0) goto resolve_goto; // JUMPI
pop();
push(0x00);
push(0x00);
swap(1);
sload();
swap(1);
push(0x0100);
EVM_exp();
swap(1);
div();
push(0xffffffffffffffffffffffffffffffffffffffff);
and();
push(0xffffffffffffffffffffffffffffffffffffffff);
and();
dup(4);
push(0xffffffffffffffffffffffffffffffffffffffff);
and();
eq();
iszero();
tag_0x23e:
tag_0x23f:
iszero();
push(0x0249);
if(jumpi() == 0) goto resolve_goto; // JUMPI
push(0x0002);
goto resolve_goto; // JUMP
tag_0x249:
dup(3);
push(0xffffffffffffffffffffffffffffffffffffffff);
and();
dup(3);
push(0x40);
mload();
dup(1);
swap(1);
pop();
push(0x00);
push(0x40);
mload();
dup(1);
dup(4);
sub();
dup(2);
dup(6);
dup(8);
push(0x8502);
gas();
sub();
call();
swap(3);
pop();
pop();
pop();
iszero();
push(0x02dc);
if(jumpi() == 0) goto resolve_goto; // JUMPI
dup(3);
push(0xffffffffffffffffffffffffffffffffffffffff);
and();
push(0x9735b0cb909f3d21d5c16bbcccd272d85fa11446f6d679f6ecb170d2dabfecfc);
dup(4);
push(0x40);
mload();
dup(1);
dup(3);
dup(2);
mstore();
push(0x20);
add();
swap(2);
pop();
pop();
push(0x40);
mload();
dup(1);
swap(2);
sub();
swap(1);
EVM_log(3);
push(0x01);
swap(1);
pop();
push(0x02e6);
goto resolve_goto; // JUMP
push(0x02e5);
goto resolve_goto; // JUMP
tag_0x2dc:
push(0x00);
swap(1);
pop();
push(0x02e6);
goto resolve_goto; // JUMP
tag_0x2e5:
tag_0x2e6:
swap(3);
swap(2);
pop();
pop();

resolve_goto:
switch(pop()) {
case 0x2a: goto tag_0x2a;
case 0x6e: goto tag_0x6e;
case 0x5e: goto tag_0x5e;
case 0x62: goto tag_0x62;
case 0x75: goto tag_0x75;
case 0x77: goto tag_0x77;
case 0x79: goto tag_0x79;
case 0x98: goto tag_0x98;
case 0xae: goto tag_0xae;
case 0xbb: goto tag_0xbb;
case 0xd1: goto tag_0xd1;
case 0xde: goto tag_0xde;
case 0x10a: goto tag_0x10a;
case 0x117: goto tag_0x117;
case 0x12d: goto tag_0x12d;
case 0x153: goto tag_0x153;
case 0x166: goto tag_0x166;
case 0x16f: goto tag_0x16f;
case 0x1ce: goto tag_0x1ce;
case 0x23e: goto tag_0x23e;
case 0x23f: goto tag_0x23f;
case 0x249: goto tag_0x249;
case 0x2dc: goto tag_0x2dc;
case 0x2e5: goto tag_0x2e5;
case 0x2e6: goto tag_0x2e6;
default: printf('Invalid JUMP resolved');
}
