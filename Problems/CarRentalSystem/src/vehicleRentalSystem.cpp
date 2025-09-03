#include "../include/vehicleRentalSystem.h"

VehicleRentalSystem::VehicleRentalSystem(vector<Store> store, vector<User> user)
	: storeList(store), userList(user) {}

Store VehicleRentalSystem::getStore(Location location) {
	for (const auto& store : storeList) {
		if (store.storeLocation &&
			store.storeLocation->address == location.address &&
			store.storeLocation->city == location.city &&
			store.storeLocation->state == location.state &&
			store.storeLocation->country == location.country &&
			store.storeLocation->pincode == location.pincode) {
			return store;
		}
	}
	// If no match found, return the first store or handle as needed
	return storeList[0];
}