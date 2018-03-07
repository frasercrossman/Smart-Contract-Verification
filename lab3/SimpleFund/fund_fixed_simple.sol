pragma solidity ^0.4.11;

contract Fund {
    /// Mapping of ether shares of the contract.
    uint fund_balance = 150;

    /// Withdraw your share.
    function withdraw() public {
        uint money = fund_balance;
        fund_balance = 0;
        msg.sender.transfer(money);
    }
}
