#pragma once
#include "vendingMachineState.h"
using namespace std;

class collectMoneyState : public vendingMachineState {
public: 
    void insertCoin(vendingMachine& vm, double amount) override;
};