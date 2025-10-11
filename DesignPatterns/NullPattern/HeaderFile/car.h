#pragma once
#include "vehicle.h"
#include <iostream>
using namespace std;

class Car : public Vehicle {
    public:
        void start() override {
            cout<<"Car started"<<endl;
        }

        void drive() override {
            cout<<"Car is driving"<<endl;
        }

        string getType() override {
            return "Car";
        }
};