#pragma once
#include "split.h"
#include <vector>
using namespace std;

class ExpenseSplit{
public:
    virtual void validateSplitRequest(vector<Split*> splitList, double totalAmount) = 0;
};