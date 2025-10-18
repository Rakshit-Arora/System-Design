#pragma once
#include "../atm.h"
#include "../transactionType.h"
#include "../card.h"
using namespace std;

class ATM;

class ATMState {
public: 
    virtual void insertCard(ATM* atm, Card* card) {cout << "OOPS!! Something went wrong!" << endl;};
    virtual void authenticatePIN(ATM* atm, Card* card, int pin) {cout << "OOPS!! Something went wrong!" << endl;};
    virtual void selectOperation(ATM* atm, Card* card, TransactionType type) {cout << "OOPS!! Something went wrong!" << endl;};
    virtual void cashWithdrawal(ATM* atm, Card* card, int amount) {cout << "OOPS!! Something went wrong!" << endl;};
    virtual void displayBalance(ATM* atm, Card* card) {cout << "OOPS!! Something went wrong!" << endl;};
    virtual void returnCard(ATM* atm) {cout << "OOPS!! Something went wrong!" << endl;};
    virtual void exit(ATM* atm) {cout << "OOPS!! Something went wrong!" << endl;};
    virtual ~ATMState() = default;
};