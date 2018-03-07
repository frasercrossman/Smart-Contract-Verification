pragma solidity ^0.4.11;

contract DivByZero {
    function divide(int numerator, int denominator) public pure returns(int) {
        return numerator / denominator;
    }
}
