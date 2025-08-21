#pragma once
#include "observer.h"
using namespace std;

// Customer is an observer that gets notified about stock changes
class Customer : public Observer {
    private: 
        string name;
    
    public:
        Customer(const string& name);

        // Called when StockItem notifies about "back in stock"
        void update(const string &itemName, int quantity) override;
};
