pragma solidity ^0.4.11;

contract Fund {
    /// Mapping of ether shares of the contract.
    mapping(address => uint) shares;

    /// Withdraw your share.
    function withdraw() public {
        var share = shares[msg.sender];
        shares[msg.sender] = 0;
        msg.sender.transfer(share);
    }
}
