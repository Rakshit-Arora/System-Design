#pragma once
#include <vector>
#include "vehicleInventoryManagement.h"
#include "reservation.h"
#include "location.h"
using namespace std;

class Store {
public:
    int storeId;
    VehicleInventoryManagement inventoryManagement;
    vector<Reservation> reservations;
    Location* storeLocation;
    Store();
    void setVehicles(vector<Vehicle*> vehicles);
    vector<Vehicle*> getVehicles(VehicleType type);
    Reservation createReservation(Vehicle* vehicle, User user);
    bool completeReservation(int reservationID);
};
