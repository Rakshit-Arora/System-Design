#include "vendingMachine.h"
#include "../states/idleState.h"
#include "../states/selectionState.h"
#include "../states/collectMoneyState.h"
#include "../states/dispenseState.h"
using namespace std;

vendingMachine:: vendingMachine() {
    cout<< "------------------------------------------"<<endl;
    cout<<"Stocking up the vending machine..."<<endl;
    inventory = stockUp();
    setState(new idleState());
}

void vendingMachine::setState(vendingMachineState* state) {
    currentState.reset(state);
}

vendingMachineState* vendingMachine::getState() {
    return currentState.get();
}

vector<Product>& vendingMachine::getInventory() {
    return inventory;
}

Product* vendingMachine::getSelectedProduct() {
    return selectedProduct;
}

void vendingMachine::setSelectedProduct(Product* p) {
    selectedProduct = p;
}

void vendingMachine::setPaymentMade(double paid) {
    paymentMade = paid;
    changeToReturn = paid - (selectedProduct ? selectedProduct->price : 0);
}

double vendingMachine::getChange() const {
    return changeToReturn;
}

void vendingMachine::initiateRefund(double amt) {
    cout << "Refunding amount: " << amt << endl;
    changeToReturn = 0;
}

void vendingMachine::displayInventory() {
    cout << "Current Inventory:" << endl;

    for (const auto& product : inventory) cout << product.toString() << endl;
}

void vendingMachine::beginTransaction() {
    currentState->beginTransaction(*this);
}

void vendingMachine::chooseProduct(const string& productCode) {
    currentState->chooseProduct(*this, productCode);
}

void vendingMachine::insertCoin(double amount) {
    currentState->insertCoin(*this, amount);
}

void vendingMachine::dispenseProduct() {
    currentState->dispenseProduct(*this);
}

vector<Product> vendingMachine::stockUp() {
    return { 
        {ProductType::SOFT_DRINKS, "Coke", 70.00, "101", 5}, 
        {ProductType::SOFT_DRINKS, "Pepsi", 50.00, "102", 5}, 
        {ProductType::SOFT_DRINKS, "Sprite", 50.00, "103", 5}, 
        {ProductType::CHIPS, "Lays", 20.00, "201", 5}, 
        {ProductType::CHIPS, "Nachos", 60.00, "202", 5}, 
        {ProductType::CHIPS, "Pringles", 50.00, "203", 5}, 
        {ProductType::CHOCOLATE, "Munch", 20.00, "301", 5}, 
        {ProductType::CHOCOLATE, "Snickers", 50.00, "302", 5}, 
        {ProductType::CHOCOLATE, "5Star", 35.00, "303", 1} 
    };
}

