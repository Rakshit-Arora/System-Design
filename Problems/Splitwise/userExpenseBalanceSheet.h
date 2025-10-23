#pragma once
#include <map>
#include "balance.h"
using namespace std;

class UserExpenseBalanceSheet {
private:
    map<string, Balance*> userVsBalance; // Key: UserID, Value: Balance
    double totalYourExpense;
    double totalPayment;
    double totalYouOwe;
    double totalYouGetBack;

public:
    UserExpenseBalanceSheet(): userVsBalance(), totalYourExpense(0.0), totalPayment(0.0), totalYouOwe(0.0), totalYouGetBack(0.0) {}

    // non-const getter so callers can modify the map (operator[], insert, etc.)
    map<string, Balance*>& getUserVsBalance() {
        return userVsBalance;
    }

    // const getter for read-only access
    const map<string, Balance*>& getUserVsBalance() const {
        return userVsBalance;
    }

    double getTotalYourExpense() const {
        return totalYourExpense;
    }

    void setTotalYourExpense(double totalYourExpense) {
        this->totalYourExpense = totalYourExpense;
    }

    double getTotalYouOwe() const {
        return totalYouOwe;
    }

    void setTotalYouOwe(double totalYouOwe) {
        this->totalYouOwe = totalYouOwe;
    }

    void setTotalYouGetBack(double totalYouGetBack) {
        this->totalYouGetBack = totalYouGetBack;
    }

    double getTotalYouGetBack() const {
        return totalYouGetBack;
    }

    double getTotalPayment() const {
        return totalPayment;
    }

    void setTotalPayment(double totalPayment) {
        this->totalPayment = totalPayment;
    }   
};