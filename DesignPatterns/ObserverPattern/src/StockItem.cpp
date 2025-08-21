#include "../HeaderFile/stockItem.h"
#include <iostream>
using namespace std;

StockItem::StockItem(const string& itemName, int quantity)
    : itemName(itemName), quantity(quantity) {}

void StockItem::restock (int amount) {
    bool wasOutOfStock = (quantity == 0);

    quantity += amount;

    cout << "[StockItem] " << itemName << " restocked by " << amount 
         << ". Current quantity: " << quantity << "\n";

    // Notify only if it was out of stock before and now has stock
        if (wasOutOfStock && quantity > 0) {
            cout << "[StockItem] " << itemName << " is BACK IN STOCK!\n";
            notify(itemName, quantity);
    }
}

void StockItem::add(Observer *observer) {
    observers.push_back(observer);
}

void StockItem::remove(Observer *observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void StockItem::notify(const string &itemName, int quantity) {
    for (auto *observer : observers) {
        observer->update(itemName, quantity);
    }
}
