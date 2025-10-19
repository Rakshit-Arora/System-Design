#pragma once
#include <iostream>
using namespace std;

// Class containing pure vitual function is an interface class
class ArithmeticExpression {
public:
    virtual int evaluate() const = 0;
    virtual ~ArithmeticExpression() = default; 
};