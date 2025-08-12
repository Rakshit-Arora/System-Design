#include "strategy/normalDriveStrategy.h"
#include "vehicle.h"

class GoodsVehicle : public Vehicle {
public:
    GoodsVehicle() : Vehicle(new NormalDriveStrategy()) {}
};