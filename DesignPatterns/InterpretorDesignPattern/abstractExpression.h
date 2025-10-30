#pragma once
#include "context.h"

class AbstractExpression {
public:
    virtual ~AbstractExpression() = default;
    virtual int interpret(Context context) = 0;
};