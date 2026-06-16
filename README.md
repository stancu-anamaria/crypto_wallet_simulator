# crypto_wallet_simulator
A C++ cryptocurrency wallet simulator that manages digital assets, processes buy/sell transactions, and tracks portfolio balance using OOP principles.
## Overview

Crypto Wallet Simulator is a C++ application that simulates the basic functionality of a cryptocurrency wallet. The program allows users to store multiple cryptocurrencies, manage an available balance, and perform buy and sell transactions while automatically updating the portfolio.

The project was developed to simulate a cryptocurrency portfolio management system while applying Object-Oriented Programming concepts such as classes, dynamic memory allocation, encapsulation, constructors, destructors, and object interaction.


## Features

### Portfolio Management

* Store multiple cryptocurrencies in a wallet.
* Track the amount owned for each cryptocurrency.
* Track the current unit price of each cryptocurrency.
* Display the complete portfolio and available balance.

### Buying Cryptocurrencies

* Purchase a specified amount of a cryptocurrency.
* Automatically update the wallet balance.
* If the requested purchase exceeds the available balance, the program buys the maximum affordable amount.

### Selling Cryptocurrencies

* Sell a specified amount of a cryptocurrency.
* Automatically update the wallet balance.
* If the requested amount exceeds the quantity owned, the program sells only the available amount.

### Batch Transactions

* Execute multiple buy and sell operations consecutively.
* Display the final state of the wallet after all transactions have been processed.


## Technologies and Concepts

* C++
* Object-Oriented Programming (OOP)
* Classes and Objects
* Dynamic Memory Allocation
* Pointers
* Constructors and Destructors
* Encapsulation
* Portfolio Management Logic



## Project Structure

### Class `Criptomoneda`

Represents a cryptocurrency stored in the wallet.

Attributes:

* nume – cryptocurrency name
* val_fractionara – amount owned
* val_curenta – current value per unit

Responsibilities:

* Store cryptocurrency information
* Update owned quantity
* Display cryptocurrency data

### Class `Portofel`

Represents the user's digital wallet.

Attributes:

* sold_initial – available balance
* n – number of stored cryptocurrencies
* capacitate – maximum portfolio capacity
* Criptomoneda** c – dynamically allocated collection of cryptocurrencies

Responsibilities:

* Manage available balance
* Store cryptocurrencies
* Process buy operations
* Process sell operations
* Handle transaction sequences

