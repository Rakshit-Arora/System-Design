#pragma once
#include "vendingMachineState.h"
using namespace std;

class selectionState : public vendingMachineState {
public:
    void chooseProduct(vendingMachine& vm, const string& productCode) override;
};