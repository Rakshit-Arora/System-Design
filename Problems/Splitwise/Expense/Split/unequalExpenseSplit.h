#pragma once
#include "split.h"
#include "expenseSplit.h"
using namespace std;

class UnequalExpenseSplit : public ExpenseSplit {
public:
    void validateSplitRequest(vector<Split*> splitList, double totalAmount) override {
        double totalSplitAmount = 0.0;
        for (auto& split : splitList) {
            double amountOwe = split->getAmountOwe();
            if (amountOwe < 0) {
                throw invalid_argument("Invalid split: Amount owed cannot be negative.");
            }
            totalSplitAmount += amountOwe;
        }
        
        if (abs(totalSplitAmount - totalAmount) > 1e-6) {
            throw invalid_argument("Invalid split: Total split amount does not equal total expense amount.");
        }
    }
};