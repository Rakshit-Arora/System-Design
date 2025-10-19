#pragma once

class AdapterWeightMachine {
public:
    virtual double getWeightInKg() = 0; // client expects weight in kilograms
    virtual ~AdapterWeightMachine() = default;
};