#pragma once
#include "../Implementor/breathingProcess.h"
#include <iostream>
using namespace std;

class Photosynthesis : public BreathingProcess {
public:
    void breathe() override {
        cout << "Breating through Photosyntesis" << endl;
    }
};