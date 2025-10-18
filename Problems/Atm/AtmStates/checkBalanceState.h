#pragma once
#include "atmState.h"
#include "idleState.h"
using namespace std;

class CheckBalanceState : public ATMState {
public: 
    void displayBalance(ATM* atm, Card* card) override {
        cout << "Your current bank balance is: " << card -> getBankBalance() << endl;
        exit(atm);
    }

    void exit(ATM* atm) override {
        returnCard(atm);
        atm->setCurrentATMState(new IdleState());
        cout << "Exited to Main Menu" << endl;
    }

    void returnCard(ATM* /*atm*/) override {
        cout << "Please take your card back." << endl;
    }
};
