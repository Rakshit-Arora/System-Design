#include "dispenseState.h"
#include "../context/vendingMachine.h"
#include "idleState.h"
#include <iostream>
using namespace std;

void dispenseState::dispenseProduct(vendingMachine& vm) {
    cout<<"CurrentState: DispenseState"<<endl;
    auto *prod = vm.getSelectedProduct();

    cout<< "Dispensing product: " << prod->name<< endl;
    cout<< "Change returned: " << vm.getChange() << endl;
    prod->quantity -= 1;

    vm.setState(new idleState());
}