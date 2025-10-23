#pragma once
#include "expense.h"
#include "Split/equalExpenseSplit.h"
#include "Split/unequalExpenseSplit.h"
#include "Split/percentageExpenseSplit.h"
#include "Split/expenseSplit.h"

class SplitFactory {
public:
    static ExpenseSplit* getSplitObject(ExpenseSplitType splitType) {
        switch (splitType) {
            case ExpenseSplitType::EQUAL:
                return new EqualExpenseSplit();
            case ExpenseSplitType::UNEQUAL:
                return new UnequalExpenseSplit();
            case ExpenseSplitType::PERCENTAGE:
                return new PercentageExpenseSplit();
            default:
                throw invalid_argument("Invalid Expense Split Type");
        }
    }
};