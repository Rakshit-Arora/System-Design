#include "strategy/sportsDriveStrategy.h"
#include "vehicle.h"

class SportsVehicle : public Vehicle {
    public:
    SportsVehicle() : Vehicle(new SportsDriveStrategy()) {}
};