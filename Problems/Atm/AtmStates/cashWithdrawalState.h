#pragma once
#include "atmState.h"
#include "../AmountWithdrawal/twoThousandWithdrawProcessor.h"
#include "../AmountWithdrawal/fiveHundredWithdrawProcessor.h"
#include "../AmountWithdrawal/oneHundredWithdrawProcessor.h"
#include "idleState.h"
using namespace std;

class CashWithdrawalState : public ATMState {
public: 
    CashWithdrawalState() {
        cout << "Enter the amount to withdraw:" << endl;
    }

    void cashWithdrawal(ATM* atm, Card* card, int amount) override {
        if(atm -> getATMBalance() < amount) {
            cout << "ATM has insufficient balance to process this withdrawal." << endl;
            exit(atm);
        }else if(card -> getBankBalance() < amount) {
            cout << "Your bank account has insufficient balance to process this withdrawal." << endl;
            exit(atm);
        } else {
            card -> deductBankBalance(amount);
            atm -> deductATMBalance(amount);

            CashWithdrawProcessor* processor = new TwoThousandWithdrawProcessor(new FiveHundredWithdrawProcessor(new OneHundredWithdrawProcessor(nullptr)));

            processor -> withdraw(atm, amount);
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
