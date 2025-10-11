#pragma once
#include "vehicle.h"
using namespace std;

class NullVehicle : public Vehicle {
    public:
        void start() override {
            // Do nothing
        }

        void drive() override {
            // Do nothing
        }

        string getType() override {
            return "No Vehicle";
        }
};