#pragma once
#include "../Expense/expense.h"
#include "../Expense/expenseController.h"
#include "../Expense/expenseSplitType.h"
#include "../Expense/Split/split.h"
#include "../User/user.h"
#include <vector>
#include <string>
using namespace std;

class Group {
private:
    string groupId;
    string groupName;
    vector<User*> groupMembers;
    ExpenseController* expenseController;
    vector<Expense*> expenseList;

public:
    Group() = default;

    void addMember(User& member) {
        groupMembers.push_back(&member);
    }

    string getGroupId() const {
        return groupId;
    }

    void setGroupId(const string& groupId) {
        this->groupId = groupId;
    }

    void setGroupName(const string& groupName) {
        this->groupName = groupName;
    }

    string getGroupName() const {
        return groupName;
    }

    void setExpenseController(ExpenseController* ec) {
        this->expenseController = ec;
    }

    Expense* createExpense(string expenseId,
                          string description,
                          double expenseAmount,
                          User* paidByUser,
                          ExpenseSplitType splitType,
                          vector<Split*> splitList) {

    // expenseController->createExpense(...) returns an Expense*, so
    // assign it directly instead of calling new on the returned pointer.
    Expense* expense = expenseController->createExpense(expenseId, description, expenseAmount, paidByUser, splitType, splitList);

    expenseList.push_back(expense);

        return expense;
    }
};

