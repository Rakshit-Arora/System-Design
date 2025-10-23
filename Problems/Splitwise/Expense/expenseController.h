#pragma once
#include "expense.h"
#include "splitFactory.h"
#include "Split/split.h"
#include "Split/expenseSplit.h"
#include "../balanceSheetController.h"
#include <vector>
#include <string>
using namespace std;

class ExpenseController {
private:
    BalanceSheetController* balanceSheetController;

public:
    ExpenseController(BalanceSheetController* balanceSheetController)
        : balanceSheetController(balanceSheetController) {}

    Expense* createExpense(string expenseId,
                           string description,
                           double expenseAmount,
                           User* paidByUser,
                           ExpenseSplitType splitType,
                           vector<Split*> splitList) {
        // Get the appropriate ExpenseSplit object using the factory
        ExpenseSplit* expenseSplit = SplitFactory::getSplitObject(splitType);
        
        // Validate the split request
        expenseSplit->validateSplitRequest(splitList, expenseAmount);
        
        // Create the Expense object
        Expense* expense =  new Expense(expenseId, description, expenseAmount, paidByUser, splitType, splitList);

        // Update the balance sheet
        balanceSheetController->updateUserExpenseBalanceSheet(paidByUser, splitList, expenseAmount);
                        
        return expense;
    }
};
