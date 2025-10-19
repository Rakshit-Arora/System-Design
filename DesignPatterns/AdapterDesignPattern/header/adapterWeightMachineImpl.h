#pragma once
#include "adapterWeightMachine.h"
#include "existingWeightMachine.h"
#include <iostream>
using namespace std;

class AdapterWeightMachineImpl : public AdapterWeightMachine {
public:
    ExistingWeightMachine* existingWeightMachine;

    AdapterWeightMachineImpl(ExistingWeightMachine* weightInPound) : existingWeightMachine(weightInPound) {}

    double getWeightInKg() override {
        double weightInPounds = existingWeightMachine->getWeightInPounds();
        double weightInKg = weightInPounds * 0.45; // Convert pounds to kilograms
        cout << "Converting weight to kilograms: " << weightInKg << " kg" << endl;
        return weightInKg;
    }
};