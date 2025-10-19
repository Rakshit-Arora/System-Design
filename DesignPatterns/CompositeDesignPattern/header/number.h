#pragma once
#include <iostream>
#include "arithmeticExpression.h"
using namespace std;

class Number : public ArithmeticExpression {
private:
    int value;

public:
    Number(int val) : value(val) {}

    int evaluate() const override {
        cout << "Number Value is: " << value << endl;
        return value;
    }
};