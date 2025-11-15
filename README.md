# Inventory Management System

The Inventory Management System is a lightweight, efficient C++ tool designed to help users track products, quantities, and stock movements without the need for complex software. It provides a simple interface and core features suitable for small businesses, labs, warehouses, or personal use.

## Features

This implementation uses **structs and enums** (no classes or OOP) as per the project requirements:

- **Item struct**: Contains `id`, `name`, `quantity`, `price`, and `category`
- **Category enum**: Defines three categories - `Food`, `Electronics`, and `Clothing`
- **Core functions**:
  - Add new items to inventory
  - Update existing items
  - Remove items from inventory
  - List all items with formatted output
  - Compute total inventory value

## Building the Project

### Prerequisites
- C++ compiler with C++11 support (g++, clang++)
- Make (optional, for using the Makefile)

### Compilation

Using Make:
```bash
make
```

Manual compilation:
```bash
g++ -std=c++11 -Wall -Wextra -c main.cpp -o main.o
g++ -std=c++11 -Wall -Wextra -c inventory.cpp -o inventory.o
g++ -std=c++11 -Wall -Wextra -o inventory main.o inventory.o
```

## Running the Program

```bash
./inventory
```

Or using Make:
```bash
make run
```

## Usage

The program provides an interactive menu with the following options:

1. **Add Item**: Add a new item to the inventory
   - Enter unique ID, name, quantity, price, and category
   - Categories: 0=Food, 1=Electronics, 2=Clothing

2. **Update Item**: Modify an existing item's details
   - Search by ID and update name, quantity, price, or category

3. **Remove Item**: Delete an item from the inventory
   - Search by ID and remove the item

4. **List All Items**: Display all items in a formatted table
   - Shows ID, name, quantity, price, category, and total value per item

5. **Compute Total Value**: Calculate the total value of all inventory
   - Sum of (quantity × price) for all items

6. **Exit**: Close the program

## Project Structure

```
├── inventory.h       # Header file with struct, enum, and function declarations
├── inventory.cpp     # Implementation of all inventory functions
├── main.cpp          # Main program with menu-driven interface
├── Makefile          # Build configuration
└── README.md         # This file
```

## Example

```
Welcome to the Inventory Management System!

========================================
   INVENTORY MANAGEMENT SYSTEM
========================================
1. Add Item
2. Update Item
3. Remove Item
4. List All Items
5. Compute Total Value
6. Exit
----------------------------------------
Enter your choice: 1

Enter item ID: 101
Enter item name: Apple
Enter quantity: 50
Enter price: 0.99
Enter category (0=Food, 1=Electronics, 2=Clothing): 0
Item added successfully!
```

## Cleaning Build Artifacts

```bash
make clean
```

This removes all object files and the executable.
