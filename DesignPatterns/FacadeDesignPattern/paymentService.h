#pragma once
#include <iostream>
#include <string>
using namespace std;

class PaymentService{
public:
    bool makePayment(string paymentMethod) {
        cout << "Processing payment using: " << paymentMethod << endl;
        return true;
    }
};