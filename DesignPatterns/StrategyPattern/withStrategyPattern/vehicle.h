#pragma once
#include "strategy/driveStrategy.h"

class Vehicle {
    DriveStrategy* driveStrategy;
public:
    Vehicle(DriveStrategy* strategy) {
        driveStrategy = strategy;
    }
    void drive() {
        driveStrategy->drive();
    }
};
