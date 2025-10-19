#pragma once
#include "existingWeightMachine.h"
#include <iostream>
using namespace std;

class ExistingWeightMachineImpl : public ExistingWeightMachine {
private:
    double weightInPounds = 0;

public:
    ExistingWeightMachineImpl(double weight) : weightInPounds(weight) {}

    double getWeightInPounds() override {
        cout << "Getting weight in pounds: " << weightInPounds << " lbs" << endl;
        return weightInPounds;
    }
};