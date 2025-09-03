#pragma once
#include <vector>
#include "vehicle.h"
using namespace std;

class VehicleInventoryManagement {
private:
    vector<Vehicle*> vehicles;

public:
    VehicleInventoryManagement(vector<Vehicle*> v);

    vector<Vehicle*> getVehicle();
    void setVehicle(vector<Vehicle*> v);
};

