#pragma once
#include "split.h"
#include "expenseSplit.h"
using namespace std;

class EqualExpenseSplit : public ExpenseSplit {
public:
    void validateSplitRequest(vector<Split*> splitList, double totalAmount) override {
        double amountShouldBePresent = totalAmount / splitList.size();
        for (auto& split : splitList) {
            if (split->getAmountOwe() != amountShouldBePresent) {
                throw invalid_argument("Invalid split: Amount owed does not match equal share.");
            }
        }
    }
};