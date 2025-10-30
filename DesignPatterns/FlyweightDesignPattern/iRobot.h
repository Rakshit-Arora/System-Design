#pragma once

class IRobot {
public:
    virtual ~IRobot() = default;
    virtual void display(int x, int y) = 0;
};