pragma solidity ^0.4.0;

// THIS CONTRACT CONTAINS A BUG - DO NOT USE
contract Fund {
    /// Mapping of ether shares of the contract.
    uint fund_balance = 150;
    uint key = 15;

    /// Withdraw your share.
    function withdraw(uint key_guess) public {
        if (key == key_guess) {
            key = 100 - key;
        
            if (msg.sender.call.value(fund_balance)()) {
                fund_balance = 0;
            }
        }
    }
}
