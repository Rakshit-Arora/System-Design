#pragma once
#include "./iCommand.h"
#include "../Receiver/airConditioner.h"
#include <memory>

class TurnAcOff : public ICommand {
private:    
    shared_ptr<AirConditioner> ac;
    bool previousState = false;

public:
    explicit TurnAcOff(shared_ptr<AirConditioner> airConditioner): ac(move(airConditioner)) {}

    void execute() override {
        previousState = ac -> isAcOn();
        ac -> turnOff();
    }

    void undo() override {
        cout << "Undo: Turn Off Command." << endl;

        if(previousState) {
            ac -> turnOn();
        }
    }
};