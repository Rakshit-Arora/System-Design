#pragma once
#include <iostream>
using namespace std;

class UserBankAccount {
public:
    int balance;
    
    UserBankAccount(int b = 0) : balance(b) {}

    void updateBalance(int amount) {
        balance += amount;
    }

    void withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
};