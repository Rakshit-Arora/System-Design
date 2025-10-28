#pragma once
#include <iostream>
#include "../Abstraction/livingThings.h"
using namespace std;

class Tree : public LivingThings {
public:
    explicit Tree(shared_ptr<BreathingProcess> process) : LivingThings(move(process)) {}

    void breathe() override {
        cout<<"Tree: ";
        breathingProcess -> breathe();
    }
};