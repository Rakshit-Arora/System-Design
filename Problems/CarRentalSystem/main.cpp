#include <iostream>
#include "car.h"
#include "bike.h"
#include "user.h"
#include "store.h"
#include "bill.h"
#include "payment.h"
#include "vehicleRentalSystem.h"
using namespace std;

int main() {
    // Users
    User user1(1, "Rakshit", "DL1234");
    vector<User> users = {user1};

    // Vehicles
    Vehicle* car1 = new Car(1);
    Vehicle* car2 = new Car(2);
    vector<Vehicle*> vehicles = {car1, car2};

    // Store
    Store store1;
    store1.storeId = 1;
    store1.setVehicles(vehicles);
    store1.storeLocation = new Location(560001, "Bangalore", "Karnataka", "India");
    vector<Store> stores = {store1};

    // Rental System
    VehicleRentalSystem rentalSystem(stores, users);

    // Flow
    Location loc(560001, "Bangalore", "Karnataka", "India");
    Store selectedStore = rentalSystem.getStore(loc);

    vector<Vehicle*> availableVehicles = selectedStore.getVehicles(VehicleType::CAR);

    Reservation reservation = selectedStore.createReservation(availableVehicles[0], user1);

    Bill bill(reservation);

    Payment payment;
    payment.payBill(bill);

    selectedStore.completeReservation(reservation.reservationId);

    return 0;
}
