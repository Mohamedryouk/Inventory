#include "inventory.h"
#include <iostream>
#include <iomanip>

// Convert Category enum to string
const char* categoryToString(Category cat) {
    switch (cat) {
        case Food: return "Food";
        case Electronics: return "Electronics";
        case Clothing: return "Clothing";
        default: return "Unknown";
    }
}

// Add a new item to inventory
void addItem(Item* items, int& count, int maxSize) {
    if (count >= maxSize) {
        std::cout << "Inventory is full! Cannot add more items.\n";
        return;
    }
    
    Item newItem;
    std::cout << "\nEnter item ID: ";
    std::cin >> newItem.id;
    
    // Check for duplicate ID
    for (int i = 0; i < count; i++) {
        if (items[i].id == newItem.id) {
            std::cout << "Error: Item with ID " << newItem.id << " already exists!\n";
            return;
        }
    }
    
    std::cin.ignore(); // Clear newline from buffer
    std::cout << "Enter item name: ";
    std::getline(std::cin, newItem.name);
    
    std::cout << "Enter quantity: ";
    std::cin >> newItem.quantity;
    
    std::cout << "Enter price: ";
    std::cin >> newItem.price;
    
    std::cout << "Enter category (0=Food, 1=Electronics, 2=Clothing): ";
    int catChoice;
    std::cin >> catChoice;
    
    if (catChoice < 0 || catChoice > 2) {
        std::cout << "Invalid category! Defaulting to Food.\n";
        newItem.category = Food;
    } else {
        newItem.category = static_cast<Category>(catChoice);
    }
    
    items[count] = newItem;
    count++;
    
    std::cout << "Item added successfully!\n";
}

// Update an existing item
void updateItem(Item* items, int count) {
    if (count == 0) {
        std::cout << "Inventory is empty! Nothing to update.\n";
        return;
    }
    
    int id;
    std::cout << "\nEnter item ID to update: ";
    std::cin >> id;
    
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        std::cout << "Item with ID " << id << " not found!\n";
        return;
    }
    
    std::cout << "\nCurrent item details:\n";
    std::cout << "ID: " << items[index].id << "\n";
    std::cout << "Name: " << items[index].name << "\n";
    std::cout << "Quantity: " << items[index].quantity << "\n";
    std::cout << "Price: $" << std::fixed << std::setprecision(2) << items[index].price << "\n";
    std::cout << "Category: " << categoryToString(items[index].category) << "\n";
    
    std::cin.ignore(); // Clear newline from buffer
    std::cout << "\nEnter new name (or press Enter to keep current): ";
    std::string newName;
    std::getline(std::cin, newName);
    if (!newName.empty()) {
        items[index].name = newName;
    }
    
    std::cout << "Enter new quantity (or -1 to keep current): ";
    int newQuantity;
    std::cin >> newQuantity;
    if (newQuantity >= 0) {
        items[index].quantity = newQuantity;
    }
    
    std::cout << "Enter new price (or -1 to keep current): ";
    double newPrice;
    std::cin >> newPrice;
    if (newPrice >= 0) {
        items[index].price = newPrice;
    }
    
    std::cout << "Enter new category (0=Food, 1=Electronics, 2=Clothing, -1 to keep current): ";
    int catChoice;
    std::cin >> catChoice;
    if (catChoice >= 0 && catChoice <= 2) {
        items[index].category = static_cast<Category>(catChoice);
    }
    
    std::cout << "Item updated successfully!\n";
}

// Remove an item from inventory
void removeItem(Item* items, int& count) {
    if (count == 0) {
        std::cout << "Inventory is empty! Nothing to remove.\n";
        return;
    }
    
    int id;
    std::cout << "\nEnter item ID to remove: ";
    std::cin >> id;
    
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        std::cout << "Item with ID " << id << " not found!\n";
        return;
    }
    
    // Shift all items after the removed item
    for (int i = index; i < count - 1; i++) {
        items[i] = items[i + 1];
    }
    
    count--;
    std::cout << "Item removed successfully!\n";
}

// List all items in inventory
void listItems(const Item* items, int count) {
    if (count == 0) {
        std::cout << "\nInventory is empty!\n";
        return;
    }
    
    std::cout << "\n" << std::string(80, '=') << "\n";
    std::cout << "INVENTORY LIST\n";
    std::cout << std::string(80, '=') << "\n";
    std::cout << std::left << std::setw(6) << "ID" 
              << std::setw(25) << "Name" 
              << std::setw(10) << "Quantity"
              << std::setw(12) << "Price"
              << std::setw(15) << "Category"
              << std::setw(12) << "Total Value" << "\n";
    std::cout << std::string(80, '-') << "\n";
    
    for (int i = 0; i < count; i++) {
        double itemValue = items[i].quantity * items[i].price;
        std::cout << std::left << std::setw(6) << items[i].id
                  << std::setw(25) << items[i].name
                  << std::setw(10) << items[i].quantity
                  << "$" << std::fixed << std::setprecision(2) << std::setw(11) << items[i].price
                  << std::setw(15) << categoryToString(items[i].category)
                  << "$" << std::fixed << std::setprecision(2) << itemValue << "\n";
    }
    std::cout << std::string(80, '=') << "\n";
}

// Compute total value of all items in inventory
double computeTotalValue(const Item* items, int count) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += items[i].quantity * items[i].price;
    }
    return total;
}

// Display menu options
void displayMenu() {
    std::cout << "\n" << std::string(40, '=') << "\n";
    std::cout << "   INVENTORY MANAGEMENT SYSTEM\n";
    std::cout << std::string(40, '=') << "\n";
    std::cout << "1. Add Item\n";
    std::cout << "2. Update Item\n";
    std::cout << "3. Remove Item\n";
    std::cout << "4. List All Items\n";
    std::cout << "5. Compute Total Value\n";
    std::cout << "6. Exit\n";
    std::cout << std::string(40, '-') << "\n";
    std::cout << "Enter your choice: ";
}
