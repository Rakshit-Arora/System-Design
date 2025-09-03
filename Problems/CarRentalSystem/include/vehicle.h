#pragma once
#include "enums.h"
#include <string>
using namespace std;

class Vehicle {
protected:
    int vehicleId;
    int vehicleNumber;
    VehicleType vehicleType;
    string companyName;
    string modelName;
    int kmDriven;
    string manufacturingDate;
    int average;
    int cc;
    int dailyRentalCost;
    int hourlyRentalCost;
    int noOfSeat;
    Status status;

public:
    Vehicle(int id, VehicleType type);

    int getVehicleId() const;
    void setVehicleId(int id);

    VehicleType getVehicleType() const;
    void setVehicleType(VehicleType type);
};