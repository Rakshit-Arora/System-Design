#pragma once
#include "elevatorCar.h"
#include "elevatorController.h"
#include <vector>
using namespace std;

class ElevatorCreator {
public:
    vector<ElevatorCar*> cars;
    vector<ElevatorController*> controllers;

    ElevatorCreator(int n) {
        cars.reserve(n);
        for(int i = 1; i <= n; i++) {
            cars.emplace_back(new ElevatorCar(i));
        }

        controllers.reserve(n);
        for(int i = 0; i < n; i++) {
            controllers.emplace_back(new ElevatorController(cars[i]));  
        }
    }
};