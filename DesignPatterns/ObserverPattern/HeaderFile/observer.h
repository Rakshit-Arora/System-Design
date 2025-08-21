#pragma once
#include <iostream>
#include <string>
using namespace std;

class Observer{
    public:
        virtual ~Observer() = default;

        // Called by Subject (StockItem) when stock changes
        virtual void update(const string& itemName, int quantity) = 0;
};