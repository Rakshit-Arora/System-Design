#pragma once
#include <iostream>
#include "direction.h"
using namespace std;


class ElevatorDisplay {
    private:
        int floor {0};
        Direction direction {Direction::UP};
    public:
        void setDisplay(int f, Direction d) {
            floor = f;
            direction = d;
        }

        void showDisplay() {
            cout<< "[Display] Floor: "<<floor<<" | Direction: " << (direction == Direction::UP ? "UP" : "DOWN") << endl;
        }
};