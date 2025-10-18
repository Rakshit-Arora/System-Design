#include "atm.h"
#include "user.h"
#include "transactionType.h"
#include <iostream>
using namespace std;

int main() {
    ATM* atm = ATM::getATMObject();
    atm->setATMBalance(3500, 1, 2, 4); // Setting ATM balance and notes

    UserBankAccount* acc = new UserBankAccount(3000);
    Card* card = new Card();
    card->setBankAccount(acc);

    User user;
    user.setCard(card);

    atm->printCurrentATMStatus();
    atm->getCurrentATMState()->insertCard(atm, user.card);
    atm->getCurrentATMState()->authenticatePIN(atm, user.card, 112211);
    atm->getCurrentATMState()->selectOperation(atm, user.card, TransactionType::CASH_WITHDRAWAL);
    atm->getCurrentATMState()->cashWithdrawal(atm, user.card, 2700);
    atm->printCurrentATMStatus();

    return 0;
}