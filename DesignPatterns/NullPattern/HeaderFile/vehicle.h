#pragma once
#include <string>
using namespace std;

class Vehicle {
    public:
        virtual void start() = 0;
        virtual void drive() = 0;
        virtual string getType() = 0;
        virtual ~Vehicle() = default;
};