#pragma once
#include "./iCommand.h"
#include "../Receiver/airConditioner.h"
#include <memory>

class TurnAcOn : public ICommand {
private:    
    shared_ptr<AirConditioner> ac;
    bool previousState = false;

public:
    explicit TurnAcOn(shared_ptr<AirConditioner> airConditioner): ac(move(airConditioner)) {}

    void execute() override {
        previousState = ac -> isAcOn();
        ac -> turnOn();
    }

    void undo() override {
        cout << "Undo: Turn On Command." << endl;

        if(!previousState) {
            ac -> turnOff();
        }
    }
};