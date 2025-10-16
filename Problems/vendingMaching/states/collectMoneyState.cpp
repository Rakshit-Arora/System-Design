#include "collectMoneyState.h"
#include "../context/vendingMachine.h"
#include "dispenseState.h"
#include "idleState.h"
#include <iostream>
using namespace std;

void collectMoneyState::insertCoin(vendingMachine& vm, double amount) {
    cout << "CurrentState: CollectMoneyState" << endl;
    cout << "Amount inserted: " << amount << endl;

    auto *prod = vm.getSelectedProduct();

    if(amount < prod -> price) {
        vm.initiateRefund(amount);
        vm.setState(new idleState());
        throw runtime_error("Insufficient amount inserted. Refunded.");
    }

    vm.setPaymentMade(amount);
    cout << "Sufficient amount received. Preparing to dispense product." << endl;
    vm.setState(new dispenseState());
}