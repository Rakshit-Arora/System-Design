#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "product.h"
#include "../states/vendingMachineState.h"
using namespace std;

class vendingMachine {
private:
    vector<Product> inventory;
    unique_ptr<vendingMachineState> currentState;
    Product* selectedProduct = nullptr;
    double paymentMade = 0.0;
    double changeToReturn = 0.0;

public:
    vendingMachine();
    void setState(vendingMachineState* state);
    vendingMachineState* getState();

    vector<Product>& getInventory();
    Product* getSelectedProduct();
    void setSelectedProduct(Product* p);
    void setPaymentMade(double paid);
    double getChange() const;

    void initiateRefund(double amt);
    void displayInventory();

    //Delegated Actions

    void beginTransaction();
    void chooseProduct(const string& productCode);
    void insertCoin(double amount);
    void dispenseProduct();

    static vector<Product> stockUp();
};