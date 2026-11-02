// SPDX-License-Identifier: MIT
pragma solidity ^0.8.38;

contract BankAccount {

    uint public balance;

    // Deposit Ether
    function deposit() public payable {
        balance += msg.value;
    }

    // Withdraw Ether
    function withdraw(uint amount) public {
        uint value = amount * 1 ether; 

        require(value <= balance, "Insufficient balance");

        balance -= value;

        (bool success, ) = payable(msg.sender).call{value: value}("");
        require(success, "Transfer failed");
    }

    // Check balance in ETH
    function getBalance() public view returns (uint) {
        return balance / 1 ether;
    }
}