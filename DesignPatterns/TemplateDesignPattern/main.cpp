#include <iostream>
#include "bankTransfer.h"
#include "merchantPayment.h"
#include "paymentFlow.h"
using namespace std;

int main() {
    cout << "----- Template Design Pattern Demo -----" << endl;

    // one way -> Pointer way

    // cout << " Bank Transfer " << endl;
    // PaymentFlow* bankTransfer = new BankTransfer();
    // bankTransfer -> sendMoney();
    // bankTransfer -> logTransaction();
    // delete bankTransfer;

    // cout << " Merchant Payment " << endl;
    // PaymentFlow* merchantPayment = new MerchantPayment();
    // merchantPayment -> sendMoney();
    // merchantPayment -> logTransaction();
    // delete merchantPayment;

    //Another way -> stack allocation

    cout << " Bank Transfer " << endl;
    BankTransfer bankTransfer;
    bankTransfer.sendMoney();
    bankTransfer.logTransaction();

    cout << " Merchant Payment " << endl;
    MerchantPayment merchantPayment;
    merchantPayment.sendMoney();
    merchantPayment.logTransaction();

    return 0;
}
