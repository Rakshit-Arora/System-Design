#pragma once
#include "./iCommand.h"
#include "../Receiver/airConditioner.h"
#include <memory>

class SetTemperature : public ICommand {
private:    
    shared_ptr<AirConditioner> ac;
    int newTemperature;
    int previousTemperature;

public:
    explicit SetTemperature(shared_ptr<AirConditioner> airConditioner, int temp): ac(move(airConditioner)), newTemperature(temp) {}

    void execute() override {
        previousTemperature = ac -> getTemperature();
        ac -> setTemperature(newTemperature);
    }

    void undo() override {
        cout << "Undo: Set Temperature Command." << endl;

        ac -> setTemperature(previousTemperature);
    }
};