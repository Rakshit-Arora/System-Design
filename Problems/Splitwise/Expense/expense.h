#pragma once
#include "Split/split.h"
#include "../User/user.h"
#include "expenseSplitType.h"
#include <vector>
#include <string>
using namespace std;

class Expense {
private:
    string expenseId;
    string description;
    double expneseAmount;
    User* paidByUser;
    ExpenseSplitType splitType;
    vector<Split*> splitList;

public:
    Expense(string expenseId, 
            string description, 
            double expneseAmount, 
            User* paidByUser, 
            ExpenseSplitType splitType, 
            vector<Split*> splitList)
        : expenseId(expenseId), 
        description(description), 
        expneseAmount(expneseAmount), 
        paidByUser(paidByUser), 
        splitType(splitType), 
        splitList(splitList) {}

};