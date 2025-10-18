#pragma once
#include <iostream>
using namespace std;

enum class TransactionType {
   CASH_WITHDRAWAL,
   BALANCE_CHECK,
};

void showAllTransactionTypes() {
    cout << "Available Transaction Types:" << endl;
    cout << "1. CASH_WITHDRAWAL" << endl;
    cout << "2. BALANCE_CHECK" << endl;
}