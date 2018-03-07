pragma solidity ^0.4.11;

contract SendBalance {
    mapping (address => uint) userBalances;
    
    function SendBalance() public payable {}

    function getBalance(address u) public constant returns(uint) {
        return userBalances[u];
    }

    function addToBalance() public payable {
        userBalances[msg.sender] += msg.value;
    }

    function withdrawBalance() public {
        if (!(msg.sender.call.value(userBalances[msg.sender])())) {
            revert();
        }
        userBalances[msg.sender] = 0;
    }
}
