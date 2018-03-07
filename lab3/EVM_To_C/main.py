import io, struct
from opcode_values import *


def main():
    with open('myfile.txt', 'r') as fin:
        # Read EVM data string
        data_string = fin.read()
        # Convert data string to int list (without the new line)
        data_list = [int(data_string[i:i+2], 16) for i in range(0, len(data_string) - 1, 2)]

        for i in range(0, len(data_list)):
            # Stop and Arithmetic
            if data_list[i] == STOP:
                print("found a stop")

            # Comparison and Bitwise Logic

            # SHA3

            # Environment Information

            # Block Information

            # Stack, Memory, Storage and Flow Operations

            # Push Operations

            # Duplicate Operations

            # Exchange Operations

            # Logging

            # System


if __name__ == "__main__":
    main()