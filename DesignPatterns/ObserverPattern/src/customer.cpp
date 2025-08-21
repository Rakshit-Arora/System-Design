#include "../HeaderFile/customer.h"
#include <iostream>
using namespace std;

Customer::Customer(const string& name) : name(name) {}

void Customer :: update(const string &itemName, int quantity) {
    cout << "[Customer] " << name << " notified: " << itemName << " is back in stock! Quantity: " << quantity << "\n";
}