#pragma once
#include <iostream>
#include "arithmeticExpression.h"
#include "operationType.h"
using namespace std;

class Expression : public ArithmeticExpression {
private:
    ArithmeticExpression* leftExpression;
    ArithmeticExpression* rightExpression;
    OperationType operationType;

public:
    Expression(ArithmeticExpression* left, ArithmeticExpression* right, OperationType opType) {
        this->leftExpression = left;
        this->rightExpression = right;
        this->operationType = opType;   
    }

    int evaluate() const override {
        int value = 0;
        switch (operationType) {
            
            case OperationType::ADD:
                value = leftExpression->evaluate() + rightExpression->evaluate();
                break;
            case OperationType::SUBTRACT:
                value = leftExpression->evaluate() - rightExpression->evaluate();
                break;
            case OperationType::MULTIPLY:
                value = leftExpression->evaluate() * rightExpression->evaluate();
                break;
            case OperationType::DIVIDE:
                value = leftExpression->evaluate() / rightExpression->evaluate();
                break;
        }
        cout<<"Expression Value is: "<<value<<endl;
        return value;
    }
};