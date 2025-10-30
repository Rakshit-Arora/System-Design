#pragma once
#include "abstractExpression.h"

class BinaryNonTerminalExpression : public AbstractExpression {
private:
    AbstractExpression* rightExpression;
    AbstractExpression* leftExpression;
    char operat;

public:
    BinaryNonTerminalExpression(AbstractExpression* left, AbstractExpression* right, char oper) : leftExpression(left), rightExpression(right), operat(oper) {}

    int interpret(Context context) override {
        switch (operat) {
            case '+':
                return leftExpression -> interpret(context) + rightExpression -> interpret(context);
            case '*':
                return leftExpression -> interpret(context) * rightExpression -> interpret(context);
            default:
                return 0;
        }
    }
};