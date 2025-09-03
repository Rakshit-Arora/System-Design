#include "../include/vehicle.h"

Vehicle:: Vehicle(int id, VehicleType type) : vehicleId(id), vehicleType(type) {};

int Vehicle:: getVehicleId() const {return vehicleId;}

void Vehicle:: setVehicleId(int id) { vehicleId = id; }

VehicleType Vehicle:: getVehicleType() const { return vehicleType; }
void Vehicle:: setVehicleType(VehicleType type) { vehicleType = type; }


