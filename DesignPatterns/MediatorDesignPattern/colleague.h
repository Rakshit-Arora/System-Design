#pragma once
#include <string>
using namespace std;

class Colleague {
public:
    virtual ~Colleague() = default;
    virtual void placeBid(double amount) = 0;
    virtual void receiveBidNotification(double bidAmount) = 0;
    virtual string getName() = 0;
};