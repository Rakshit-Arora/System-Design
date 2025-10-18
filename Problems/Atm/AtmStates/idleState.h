#pragma once
#include "atmState.h"
using namespace std;

class IdleState : public ATMState {
public:
    void insertCard(ATM* atm, Card* card) override;
};

#include "hasCardState.h"

inline void IdleState::insertCard(ATM* atm, Card* /*card*/) {
    cout << "Card inserted successfully." << endl;
    atm->setCurrentATMState(new HasCardState());
}
