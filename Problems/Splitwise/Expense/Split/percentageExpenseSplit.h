#pragma once
#include "split.h"
#include "expenseSplit.h"
using namespace std;

class PercentageExpenseSplit : public ExpenseSplit {
public:
    void validateSplitRequest(vector<Split*> splitList, double totalAmount) override {
        double totalPercentage = 0.0;
        for (auto& split : splitList) {
            double percentage = split->getAmountOwe();
            if (percentage < 0 || percentage > 100) {
                throw invalid_argument("Invalid split: Percentage must be between 0 and 100.");
            }
            totalPercentage += percentage;
        }
        
        if (abs(totalPercentage - 100.0) > 1e-6) {
            throw invalid_argument("Invalid split: Total percentage does not equal 100%.");
        }
    }
};