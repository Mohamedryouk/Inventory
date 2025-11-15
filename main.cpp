#include "inventory.h"
#include <iostream>
#include <iomanip>

int main() {
    const int MAX_ITEMS = 100;
    Item inventory[MAX_ITEMS];
    int itemCount = 0;
    
    std::cout << "Welcome to the Inventory Management System!\n";
    std::cout << "This system uses structs and enums (no OOP/classes)\n";
    
    int choice;
    bool running = true;
    
    while (running) {
        displayMenu();
        std::cin >> choice;
        
        // Clear input error state if invalid input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        
        switch (choice) {
            case 1:
                addItem(inventory, itemCount, MAX_ITEMS);
                break;
            case 2:
                updateItem(inventory, itemCount);
                break;
            case 3:
                removeItem(inventory, itemCount);
                break;
            case 4:
                listItems(inventory, itemCount);
                break;
            case 5: {
                double total = computeTotalValue(inventory, itemCount);
                std::cout << "\nTotal inventory value: $" 
                          << std::fixed << std::setprecision(2) << total << "\n";
                break;
            }
            case 6:
                std::cout << "\nThank you for using the Inventory Management System!\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice! Please select 1-6.\n";
        }
    }
    
    return 0;
}
