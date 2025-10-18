#pragma once
#include "userBankAccount.h"
using namespace std;

class Card {
public:
    static const int PIN_NUMBER = 112211;
    UserBankAccount* bankAccount = nullptr;

    bool isCorrectPINEntered(int pin) {
        return pin == PIN_NUMBER;
    }

    int getBankBalance() {
        return bankAccount ? bankAccount->balance : 0;
    }

    void deductBankBalance(int amt) {
        if(bankAccount) {
            bankAccount->withdraw(amt);
        }
    }

    void setBankAccount(UserBankAccount* account) {
        bankAccount = account;
    }
};
