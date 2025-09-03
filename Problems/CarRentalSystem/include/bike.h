#pragma once
#include "vehicle.h"
using namespace std;

class Bike: public Vehicle {
public:
    Bike(int id): Vehicle(id, VehicleType::BIKE) {};
};