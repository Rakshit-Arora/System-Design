#pragma once
#include "abstractExpression.h"

class AddNonTerminalExpression : public AbstractExpression {
private:
    AbstractExpression* rightExpression;
    AbstractExpression* leftExpression;

public:
    AddNonTerminalExpression(AbstractExpression* left, AbstractExpression* right) : leftExpression(left), rightExpression(right) {}

    int interpret(Context context) override {
        return leftExpression -> interpret(context) + rightExpression -> interpret(context);
    }
};