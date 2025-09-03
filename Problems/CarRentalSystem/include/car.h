#pragma once
#include "vehicle.h"
using namespace std;

class Car: public Vehicle {
public:
    Car(int id): Vehicle(id, VehicleType::CAR) {};
};