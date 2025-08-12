#include "strategy/sportsDriveStrategy.h"
#include "vehicle.h"

class OffRoadVehicle : public Vehicle {
    public:
    OffRoadVehicle() : Vehicle(new SportsDriveStrategy()) {}
};