# Coffee Shop Management System

A console-based Coffee Shop Management System developed in C++.

This project was created as a university C++ project to practice Object-Oriented Programming, file handling, data structures, and basic input validation.

## Features

* Display food, hot drink, and cold drink menus
* Store customer name and phone number
* Select multiple products for an order
* Calculate the total order price
* Save order information to a text file
* Record daily income
* Generate a daily income report
* Save menu information to a text file
* Basic validation for product and category selections

## Technologies

* C++
* Object-Oriented Programming (OOP)
* Standard Library
* File Handling (`ifstream` / `ofstream`)
* `vector`
* Classes and Constructors
* Loops and Conditional Statements

## Project Structure

```text
Coffee-Shop-Management-System/
│
├── finalcoffeeshop.cpp
├── README.md
└── .gitignore
```

## How It Works

The program first displays the available food, hot drinks, and cold drinks.

The user then enters:

1. The date
2. Customer name
3. Customer phone number
4. Number of products to order
5. Selected products

The program calculates the total price and stores the order information in a text file.

It also records the income and generates a daily income report.

## File Handling

The program uses:

* `ofstream` to write data to files
* `ifstream` to read daily income data

The following files are generated when the program runs:

* `menu.txt`
* `order_*.txt`
* `daily_income.txt`
* `daily_report_*.txt`

These generated files are excluded from Git using `.gitignore`.

## C++ Concepts Used

This project demonstrates several fundamental C++ concepts:

* Classes and Objects
* Constructors
* Arrays
* `vector`
* References
* Functions
* Loops
* Conditional Statements
* File Handling
* Basic Input Validation

## How to Run

A C++ compiler is required.

For example, with Microsoft Visual C++ (MSVC):

```bash
cl /EHsc finalcoffeeshop.cpp
finalcoffeeshop.exe
```

## Future Improvements

Possible future improvements include:

* Adding product quantities
* Improving input validation
* Validating the date format
* Separating product data from the source code
* Improving data management
* Adding a graphical user interface (GUI)

## Author

**Aida Adineh**

Computer Engineering Student
