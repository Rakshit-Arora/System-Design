#pragma once
#include <iostream>
using namespace std;

class ElevatorDoor {
    public:
        void openDoor() {
            cout << "[Door] Opening door." << endl;
        }

        void closeDoor() {
            cout << "[Door] Closing door." << endl;
        }
};