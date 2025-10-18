#pragma once
#include "atmState.h"
#include "cashWithdrawalState.h"
#include "checkBalanceState.h"
#include "idleState.h"
using namespace std;

class SelectOperationState : public ATMState {
public:
    SelectOperationState() {
        cout<< "Please select your operation type:" << endl;
        showAllTransactionTypes();
    }

    void selectOperation(ATM* atm, Card* card, TransactionType txnType) override {
        switch (txnType) {
            case TransactionType::CASH_WITHDRAWAL:
                atm -> setCurrentATMState(new CashWithdrawalState());
                break;
            case TransactionType::BALANCE_CHECK:
                atm -> setCurrentATMState(new CheckBalanceState());
                break;
            default:
                cout << "Invalid Transaction Type Selected!" << endl;
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
