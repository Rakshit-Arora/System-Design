#pragma once
#include "vehicle.h"
#include <iostream>
using namespace std;

class Bike : public Vehicle {
    public:
        void start() override {
            cout<<"Bike started"<<endl;
        }

        void drive() override {
            cout<<"Bike is driving"<<endl;
        }

        string getType() override {
            return "Bike";
        }
};