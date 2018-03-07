# SendBalance
The SendBalance contract presents a simple depositing system for
Ethereum. It enables the user to deposit, view and withdraw their currency.

The contract is vulnerable to a reentrancy bug.

The withdraw function sends the balance of the users account to them
by calling their default function with the associated value in their
account, and then on return zeros their account.

If the default function calls the withdraw function again the account
holder can drain the contract of its ether.

Using the default function to call withdrawBalance can be done until the
contract is emptied of Ether - or it depletes available gas - whichever
comes first.

Using Remix I exploited this exploit to drain funds from a virtual account.
