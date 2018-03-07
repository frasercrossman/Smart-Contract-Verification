pragma solidity ^0.4.11;

contract LocalArrayAccessViolation {
    function populate_array(uint256 value_count) public {
        // Create fixed byte array in local memory, length 10
        uint[] memory a = new uint[](10);
        
        // Populate array with value_count values
        for(uint256 i = 0; i < value_count; i++) {
            a[i] = 0x01;
        }
    }
}
