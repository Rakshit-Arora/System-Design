#pragma once
#include "../userExpenseBalanceSheet.h"
#include <string>
using namespace std;

class User{
private:
    string userId;
    string userName;
    std::unique_ptr<UserExpenseBalanceSheet> userExpenseBalanceSheet;

public:
    User(string userId, string userName)
        : userId(userId), userName(userName), userExpenseBalanceSheet(std::make_unique<UserExpenseBalanceSheet>()) {}

    string getUserId() const {
        return userId;
    }

    UserExpenseBalanceSheet* getUserExpenseBalanceSheet() const {
        return userExpenseBalanceSheet.get();
    }
};
