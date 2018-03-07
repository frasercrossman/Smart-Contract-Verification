pragma solidity ^0.4.8;

contract SumContract {

    // Empty constructor
    function SumContract() {}

    // Calculate Sum to N
    function SumToN(int8 N) constant returns (int8 s) {
        s = 0;
        int8 n = N;
        while (n > 0) {
            s = s + n;
            n = n - 1;
        }
    }
}
