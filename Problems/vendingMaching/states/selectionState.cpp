#include "selectionState.h"
#include "../context/vendingMachine.h"
#include "collectMoneyState.h"
#include "idleState.h"
#include <iostream>
using namespace std;

void selectionState::chooseProduct(vendingMachine& vm, const string& productCode) {
    cout << "CurrentState: SelectionState" << endl;
    cout << "Selecting Product: "<< productCode << endl;

    auto& inv = vm.getInventory();
    auto it = find_if(inv.begin(), inv.end(), [&](auto& p) {return p.code == productCode; });

    if(it == inv.end()) {
        vm.setState(new idleState());
        throw runtime_error("Invalid product code. Transaction cancelled.");
    }

    if(it -> quantity <= 0) {
        vm.setState(new idleState());
        throw runtime_error("Selected product is out of stock. Transaction cancelled.");
    }

    vm.setSelectedProduct(&(*it));
    cout << "Product selected: " << it->toString() << endl;
    vm.setState(new collectMoneyState());
}