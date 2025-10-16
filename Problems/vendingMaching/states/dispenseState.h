#pragma once
#include "vendingMachineState.h"

class dispenseState : public vendingMachineState{
public: 
    void dispenseProduct(vendingMachine& machine) override;
};