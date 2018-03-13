from opcode_values import *


def main():
    with open('ManagedAccount.bytecode', 'r') as fin:
        # Read EVM data string
        data_string = fin.read()
        # Convert data string to int list (without the new line)
        data_list = [int(data_string[i:i+2], 16) for i in range(0, len(data_string) - 1, 2)]

        jumpdests = []

        i = 0
        pc = -1
        bootstrap_code_found = False
        while i < len(data_list) - 1:
            pc = pc + 1
            # Print line number:
            # print("[" + hex(pc) + "]", end='')

            # Stop and Arithmetic
            if data_list[i] == STOP:
                print("return 0; // STOP")
            elif data_list[i] == ADD:
                print("add();")
            elif data_list[i] == MUL:
                print("mul();")
            elif data_list[i] == SUB:
                print("sub();")
            elif data_list[i] == DIV:
                print("div();")
            elif data_list[i] == SDIV:
                print("sdiv();")
            elif data_list[i] == MOD:
                print("mod();")
            elif data_list[i] == SMOD:
                print("smod();")
            elif data_list[i] == ADDMOD:
                print("addmod();")
            elif data_list[i] == MULMOD:
                print("mulmod();")
            elif data_list[i] == EXP:
                print("EVM_exp();")
            elif data_list[i] == SIGNEXTEND:
                print("signextend();")

            # Comparison and Bitwise Logic
            elif data_list[i] == LT:
                print("lt();")
            elif data_list[i] == GT:
                print("gt();")
            elif data_list[i] == SLT:
                print("slt();")
            elif data_list[i] == SGT:
                print("sgt();")
            elif data_list[i] == EQ:
                print("eq();")
            elif data_list[i] == ISZERO:
                print("iszero();")
            elif data_list[i] == AND:
                print("and();")
            elif data_list[i] == OR:
                print("or();")
            elif data_list[i] == XOR:
                print("xor();")
            elif data_list[i] == NOT:
                print("not();")
            elif data_list[i] == BYTE:
                print("byte();")

            # SHA3
            elif data_list[i] == SHA3:
                print("sha3();")

            # Environment Information
            elif data_list[i] == ADDRESS:
                print("address();")
            elif data_list[i] == BALANCE:
                print("balance();")
            elif data_list[i] == ORIGIN:
                print("origin();")
            elif data_list[i] == CALLER:
                print("caller();")
            elif data_list[i] == CALLVALUE:
                print("callvalue();")
            elif data_list[i] == CALLDATALOAD:
                print("calldataload();")
            elif data_list[i] == CALLDATASIZE:
                print("calldatasize();")
            elif data_list[i] == CALLDATACOPY:
                print("calldatacopy();")
            elif data_list[i] == CODESIZE:
                print("callsize();")
            elif data_list[i] == CODECOPY:
                print("codecopy();")
            elif data_list[i] == GASPRICE:
                print("gasprice();")
            elif data_list[i] == EXTCODESIZE:
                print("extcodesize();")
            elif data_list[i] == EXTCODECOPY:
                print("extcodecopy();")
            elif data_list[i] == RETURNDATASIZE:
                print("returndatasize();")
            elif data_list[i] == RETURNDATACOPY:
                print("returndatacopy();")
            elif data_list[i] == SIGHASH:
                print("sighash();")

            # Block Information
            elif data_list[i] == BLOCKHASH:
                print("blockhash();")
            elif data_list[i] == COINBASE:
                print("coinbase();")
            elif data_list[i] == TIMESTAMP:
                print("timestamp();")
            elif data_list[i] == NUMBER:
                print("number();")
            elif data_list[i] == DIFFICULTY:
                print("difficulty();")
            elif data_list[i] == GASLIMIT:
                print("gaslimit();")

            # Stack, Memory, Storage and Flow Operations
            elif data_list[i] == POP:
                print("pop();")
            elif data_list[i] == MLOAD:
                print("mload();")
            elif data_list[i] == MSTORE:
                print("mstore();")
            elif data_list[i] == MSTORE8:
                print("mstore();")
            elif data_list[i] == SLOAD:
                print("sload();")
            elif data_list[i] == SSTORE:
                print("sstore();")
            elif data_list[i] == JUMP:
                print("goto resolve_goto; // JUMP")
            elif data_list[i] == JUMPI:
                print("if(jumpi() == 0) goto resolve_goto; // JUMPI")
            elif data_list[i] == PC:
                print("pc();")
            elif data_list[i] == MSIZE:
                print("msize();")
            elif data_list[i] == GAS:
                print("gas();")
            elif data_list[i] == JUMPDEST:
                # Keep track of jump destinations
                jumpdests.append(hex(pc))
                print("tag_" + hex(pc) + ":")

            # Push Operations
            elif PUSH1 <= data_list[i] <= PUSH32:
                hex_val = ''.join(['{:02x}'.format(data_list[n]) for n in range(i + 1, i + 2 + data_list[i] - PUSH1)])
                print("push(0x" + hex_val + ");")
                # Progress the program counter appropriately
                pc = pc + data_list[i] - PUSH1 + 1
                i = i + data_list[i] - PUSH1 + 1

            # Duplicate Operations
            elif DUP1 <= data_list[i] <= DUP16:
                print("dup(" + str(data_list[i] - DUP1 + 1) + ");")

            # Exchange Operations
            elif SWAP1 <= data_list[i] <= SWAP16:
                print("swap(" + str(data_list[i] - SWAP1 + 1) + ");")

            # Logging
            elif LOG0 <= data_list[i] <= LOG4:
                print("EVM_log(" + str(data_list[i] - LOG0 + 1) + ");")

            # System
            elif data_list[i] == CREATE:
                print("create();")
            elif data_list[i] == CALL:
                print("call();")
            elif data_list[i] == CALLCODE:
                print("callcode();")
            elif data_list[i] == RETURN:
                print("return 0; // RETURN")
                if bootstrap_code_found == False:
                    bootstrap_code_found = True
                    # Detect Bootstrap/Bin runtime divide
                    pc = -1
            elif data_list[i] == DELEGATECALL:
                print("delegatecall();")
            elif data_list[i] == PAYGAS:
                print("paygas();")
            elif data_list[i] == STATICCALL:
                print("staticcall();")
            elif data_list[i] == CREATE2:
                print("create2();")
            elif data_list[i] == REVERT:
                print("return -1; // REVERT")
            elif data_list[i] == SELFDESTRUCT:
                print("selfdestruct();")
            else:
                print("//OPCODE NOT RECOGNISED")

            # Increment the program counter
            i = i + 1

        # Print jump destinations
        print("\nresolve_goto:")
        print("switch(pop()) {")
        for dest in jumpdests:
            print("case " + dest + ": goto tag_" + dest + ";")
        print("default: printf('Invalid JUMP resolved');")
        print("}")


if __name__ == "__main__":
    main()