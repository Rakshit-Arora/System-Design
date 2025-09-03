#include "../include/store.h"
#include <iostream>

Store:: Store() : inventoryManagement(std::vector<Vehicle*>()) {};

void Store:: setVehicles(vector<Vehicle*> vehicles) {
    inventoryManagement = VehicleInventoryManagement(vehicles);
}

vector<Vehicle*> Store:: getVehicles(VehicleType type) {
    vector<Vehicle*> filteredVehicles;
    for (auto vehicle : inventoryManagement.getVehicle()) {
        if (vehicle->getVehicleType() == type) {
            filteredVehicles.push_back(vehicle);
        }
    }
    return filteredVehicles;
}

Reservation Store:: createReservation(Vehicle* vehicle, User user) {
    Reservation reservation(1, user, vehicle);
    reservation.createReserve();
    reservations.push_back(reservation);
    return reservation;
}

bool Store:: completeReservation(int reservationId) {
    cout << "Reservation " << reservationId << " completed!" << endl;
    return true;
}

