#pragma once
#include "abstractExpression.h"

class NumberTerminalExpressoin : public AbstractExpression {
private:
    string stringVal;

public:
    NumberTerminalExpressoin(string str) : stringVal(str) {}

    int interpret(Context context) override {
        return context.getVariable(stringVal);
    }
};