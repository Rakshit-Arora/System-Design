#pragma once
#include "subject.h"
#include <algorithm>
using namespace std;

// StockItem represents a product that can go in/out of stock
class StockItem: public Subject{
    private:
        string itemName;
        int quantity;
        vector<Observer*> observers;

    public:
        StockItem(const string& itemName, int quantity);
        void restock(int amount);
        void add(Observer* observer) override;
        void remove(Observer* observer) override;
        void notify(const string& itemName, int quantity) override;
};