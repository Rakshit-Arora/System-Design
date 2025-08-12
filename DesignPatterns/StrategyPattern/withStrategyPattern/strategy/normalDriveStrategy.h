#pragma once
#include "driveStrategy.h"

class NormalDriveStrategy : public DriveStrategy {
public:
    void drive() override {
        cout << "Normal Drive Capability" << endl;
    }
};
