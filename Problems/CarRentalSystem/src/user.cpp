#include "../include/user.h"

User:: User(int id, string name, string license) : userId(id), userName(name), drivingLicense(license) {};

int User:: getUserId() const { return userId; }

string User:: getUserName() const { return userName; }