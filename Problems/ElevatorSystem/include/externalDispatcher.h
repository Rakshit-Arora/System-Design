#pragma once
#include "elevatorCreator.h"
#include "direction.h"
#include <limits>
#include <iostream>
using namespace std;

class ExternalDispatcher {
    private:
        ElevatorCreator* creator;
        
    public:
        ExternalDispatcher(ElevatorCreator* c) : creator(c) {};

        void submitExternalRequest(int floor, Direction dir) {
            int bestIdx = -1;
            int bestScore = numeric_limits<int>::max();

            for(int i = 0; i < creator->controllers.size(); i++) {
                ElevatorController* ctrl = creator->controllers[i];
                ElevatorCar* car = ctrl->elevator;

                int score = abs(car->currentFloor - floor);
                if(car->direction == dir) score -= 1;
            
                if(car ->state == ElevatorState::IDLE) score -= 2;
                
                if(score < bestScore) {
                    bestScore = score;
                    bestIdx = i;
                }
            } 

            if (bestIdx != -1) {
                cout << "[Dispatcher] Assigning floor " << floor << " to elevator " << creator->controllers[bestIdx]->elevator->id << "\n";
                creator->controllers[bestIdx]->submitRequest(floor, dir);
            }
        }
};