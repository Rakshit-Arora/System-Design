#pragma once
#include "abstractExpression.h"

class MultiplyNonTerminalExpression : public AbstractExpression {
private:
    AbstractExpression* rightExpression;
    AbstractExpression* leftExpression;

public:
    MultiplyNonTerminalExpression(AbstractExpression* left, AbstractExpression* right) : leftExpression(left), rightExpression(right) {}

    int interpret(Context context) override {
        return leftExpression -> interpret(context) * rightExpression -> interpret(context);
    }
};