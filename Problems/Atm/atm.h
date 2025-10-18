#pragma once
#include <iostream>
using namespace std;

class ATMState;

class ATM {
private:
    static ATM* atmObject; // Singleton ATM instance

    ATMState* currentATMState;
    int atmBalance;
    int noOfTwoThousandNotes;
    int noOfFiveHundredNotes;
    int noOfOneHundredNotes;

    ATM() {}

public:
    static ATM* getATMObject();

    void setCurrentATMState(ATMState* state) {
        currentATMState = state;
    }

    ATMState* getCurrentATMState() {
        return currentATMState;
    }

    void setATMBalance(int balance, int twoK, int fiveH, int oneH) {
        this -> atmBalance = balance;
        this -> noOfTwoThousandNotes = twoK;
        this -> noOfFiveHundredNotes = fiveH;
        this -> noOfOneHundredNotes = oneH;
    }

    int getATMBalance() {
        return atmBalance;
    }

    int getNoOfTwoThousandNotes() {
        return noOfTwoThousandNotes;
    }

    int getNoOfFiveHundredNotes() {
        return noOfFiveHundredNotes;
    }

    int getNoOfOneHundredNotes() {
        return noOfOneHundredNotes;
    }

    void deductATMBalance(int amount) {
        atmBalance -= amount;
    }

    void deductTwoThousandNotes(int count) {
        noOfTwoThousandNotes -= count;
    }

    void deductFiveHundredNotes(int count) {
        noOfFiveHundredNotes -= count;
    }

    void deductOneHundredNotes(int count) {
        noOfOneHundredNotes -= count;
    }

    void printCurrentATMStatus() {
        cout<< "ATM Status: " << endl;
        cout<< "ATM Balance: " << atmBalance << endl;
        cout<< "No. of 2000 Notes: " << noOfTwoThousandNotes << endl;
        cout<< "No. of 500 Notes: " << noOfFiveHundredNotes << endl;
        cout<< "No. of 100 Notes: " << noOfOneHundredNotes << endl; 
        cout<< "------------------------" << endl;
    }
};

#include "AtmStates/atmState.h"
#include "AtmStates/idleState.h"

inline ATM* ATM::getATMObject() {
    if(!atmObject) {
        atmObject = new ATM();
    }

    atmObject -> setCurrentATMState(new IdleState());
    return atmObject;
}

inline ATM* ATM::atmObject = nullptr;
