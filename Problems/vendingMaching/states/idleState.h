#pragma once
#include "vendingMachineState.h"
using namespace std;

class idleState : public vendingMachineState {
public:
    void beginTransaction(vendingMachine& vm) override;
};