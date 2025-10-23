#pragma once
#include "../../User/user.h"

class Split{
private:
    User* user;
    double amountOwe;

public:
    Split(User* user, double amountOwe) : user(user), amountOwe(amountOwe) {};

    User* getUser() const {
        return user;
    }

    void setUser(User* user) {
        this->user = user;
    }

    double getAmountOwe() const {
        return amountOwe;
    }

    void setAmountOwe(double amountOwe) {
        this->amountOwe = amountOwe;
    }
};
