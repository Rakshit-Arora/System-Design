#pragma once
#include "atmState.h"
#include "idleState.h"
#include "selectOperationState.h"
using namespace std;

class HasCardState : public ATMState {
public:
    HasCardState() { cout << "Enter Your Card Pin Number" << endl; }

    void authenticatePIN(ATM* atm, Card* card, int pin) override {
        if(card -> isCorrectPINEntered(pin)) {
            cout << "PIN authenticated successfully." << endl;
            atm->setCurrentATMState(new SelectOperationState());
        } else {
            cout << "Incorrect PIN. Please try again." << endl;
            exit(atm);
        }
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
