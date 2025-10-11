#pragma once
#include <memory>
#include <string>
#include "vehicle.h"
using namespace std;

class VehicleFactory {
    public:
        static shared_ptr<Vehicle> create(string& type);
};