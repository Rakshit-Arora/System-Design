#pragma once
#include "elevatorDoor.h"
#include "elevatorDisplay.h"
#include "elevatorState.h"
#include "direction.h"
using namespace std;

class InternalButtons;

class ElevatorCar {
    public:
        int id {0};
        int currentFloor {0};
        ElevatorState state {ElevatorState::IDLE};
        Direction direction {Direction::UP};
        ElevatorDoor door;
        ElevatorDisplay display;

        ElevatorCar(int i) : id(i) {}

        void setDisplay() {
            display.setDisplay(currentFloor, direction);
        }

        void showDisplay() {
            display.showDisplay();
        }
};