#include "../include/vehicleInventoryManagement.h"

VehicleInventoryManagement:: VehicleInventoryManagement(vector<Vehicle*> v) : vehicles(v) {}

vector<Vehicle*> VehicleInventoryManagement:: getVehicle() { return vehicles; };
void VehicleInventoryManagement:: setVehicle(vector<Vehicle*> v) { vehicles = v; };