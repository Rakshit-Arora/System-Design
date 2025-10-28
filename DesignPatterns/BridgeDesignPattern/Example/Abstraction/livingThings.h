#pragma once
#include "../Implementor/breathingProcess.h"
#include <memory>
using namespace std;

class LivingThings {
public:
    shared_ptr<BreathingProcess> breathingProcess;

    explicit LivingThings(shared_ptr<BreathingProcess> process) : breathingProcess(move(process)) {}

    virtual ~LivingThings() = default;

    virtual void breathe() = 0;
};

