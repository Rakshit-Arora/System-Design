#pragma once
#include "../Implementor/breathingProcess.h"
#include <iostream>
using namespace std;

class LungBreathing : public BreathingProcess {
public:
    void breathe() override {
        cout << "Breating through Lungs" << endl;
    }
};