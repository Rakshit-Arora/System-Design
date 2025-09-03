#pragma once
#include <vector>
#include "store.h"
#include "user.h"
using namespace std;

class VehicleRentalSystem {
    vector<Store> storeList;
    vector<User> userList;

public:
    VehicleRentalSystem(vector<Store> stores, vector<User> users);
    Store getStore(Location location);
};
