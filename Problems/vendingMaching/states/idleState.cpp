#include "idleState.h"
#include "../context/vendingMachine.h"
#include "selectionState.h"
#include <iostream>
using namespace std;

void idleState::beginTransaction(vendingMachine& vm) {
    cout << "CurrentState: IdleState" << endl;
    cout << "Transaction started. Please select a product." << endl;
    vm.setState(new selectionState());
}