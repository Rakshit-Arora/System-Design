#pragma once
#include <iostream>
#include "../Abstraction/livingThings.h"
using namespace std;

class Fish : public LivingThings {
public:
    explicit Fish(shared_ptr<BreathingProcess> process) : LivingThings(move(process)) {}

    void breathe() override {
        cout<<"Fish: ";
        breathingProcess -> breathe();
    }
};