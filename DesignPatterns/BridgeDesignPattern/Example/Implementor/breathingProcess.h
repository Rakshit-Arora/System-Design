#pragma once

class BreathingProcess {
public:
    virtual ~BreathingProcess() = default;
    virtual void breathe() = 0;
};
