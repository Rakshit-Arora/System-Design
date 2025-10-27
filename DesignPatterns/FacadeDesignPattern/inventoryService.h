#pragma once
#include <iostream>
#include <string>
using namespace std;

class InventoryService{
public:
    bool checkStorage(string productId) {
        cout << "Checking stock for the product: "<< productId << endl;

        return true;
    }
};