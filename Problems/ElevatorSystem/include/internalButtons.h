#pragma once
#include "internalDispatcher.h"
#include "elevatorCar.h"
#include <vector>
#include <iostream>
using namespace std;

class InternalButtons {
    private:
        InternalDispatcher* dispatcher;
        vector<int> availableButtons;

    public:
        InternalButtons(InternalDispatcher* d, int maxFloor = 10) : dispatcher(d) {
            for (int i=1;i<=maxFloor;i++) availableButtons.push_back(i);
        }

        void pressButton(int destination, ElevatorCar* car) {
        // validate
        if (destination < 1) return;
        cout << "[Inside Elevator " << car->id << "] Button pressed: " << destination << "\n";
        dispatcher->submitInternalRequest(destination, car->id);
    }
};