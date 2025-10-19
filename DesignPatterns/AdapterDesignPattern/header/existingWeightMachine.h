#pragma once

class ExistingWeightMachine {
public:
    virtual double getWeightInPounds() = 0;
    virtual ~ExistingWeightMachine() = default;
};