#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>

// Enum for item categories
enum Category {
    Food,
    Electronics,
    Clothing
};

// Struct for inventory items
struct Item {
    int id;
    std::string name;
    int quantity;
    double price;
    Category category;
};

// Function declarations
void addItem(Item* items, int& count, int maxSize);
void updateItem(Item* items, int count);
void removeItem(Item* items, int& count);
void listItems(const Item* items, int count);
double computeTotalValue(const Item* items, int count);
const char* categoryToString(Category cat);
void displayMenu();

#endif // INVENTORY_H
