#pragma once
#include <string>
using namespace std;

class User{
private:
    int userId;
    string userName;
    string drivingLicense;

public:
    User(int id, string name, string license);

    int getUserId() const;
    string getUserName() const;
};