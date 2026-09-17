# Console POS System

A C++ console-based Point of Sale (POS) system built as a learning project after completing C++ fundamentals and Object-Oriented Programming (OOP).

## Features

- User login and roles (Admin / Cashier)
- User management: add, remove, update, display
- Product management: add, remove, update, display
- Stock management: increase and decrease stock
- Product search by ID or name
- Shopping cart
- Subtotal calculation
- Sale confirmation and saving
- Sale cancellation with stock restoration
- File-based data persistence using `fstream`
- Separate screen text files for the console UI

## C++ Concepts Practiced

- Classes and objects
- Encapsulation
- `enum class`
- `std::vector`
- References
- `const` member functions
- Header/source separation (`.h` / `.cpp`)
- File I/O
- Iterators and `vector::erase`
- Basic input validation
- Separation of responsibilities between classes

## Project Structure

```text
POS/
├── Headers/
│   ├── Helpers.h
│   ├── User.h
│   ├── UserManager.h
│   ├── Product.h
│   ├── ProductManager.h
│   ├── CartItem.h
│   └── Cart.h
│
├── Implementations/
│   ├── Helpers.cpp
│   ├── User.cpp
│   ├── UserManager.cpp
│   ├── Product.cpp
│   ├── ProductManager.cpp
│   ├── CartItem.cpp
│   └── Cart.cpp
│
├── Screens/
├── Data/
├── POS.cpp
├── README.md
└── .gitignore
```

## Data Persistence

The program stores its data in text files inside the `Data` folder:

- `users.txt`
- `Products.txt`
- `Sales.txt`

The program loads the saved users and products when it starts and writes changes back to the files.

## How to Run

Compile all `.cpp` files together. For example with g++:

```bash
g++ POS.cpp Implementations/*.cpp -o POS
```

Then run the generated program from the project root so the relative paths to `Data/` and `Screens/` work correctly.

## Sample Login

The repository contains sample data for demonstration. The credentials can be found in `Data/users.txt`.

## Project Scope

This is intentionally a console-based learning project. It focuses on practicing C++ fundamentals, OOP, STL containers, file handling, program flow, and basic validation rather than implementing a production POS system.

## Possible Future Improvements

- Customer management
- Reports
- Better sale records
- Database storage
- Automated unit tests
- More advanced input handling

## This was made by: Mohammed Najeeb Al-Obadi

## User: Mohammed Al-Obadi 
## Password: 123