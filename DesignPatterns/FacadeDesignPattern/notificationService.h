#pragma once
#include <iostream>
using namespace std;

class NotificationService{
public:
    void sendConfirmation(string productId) {
        cout << "Sending order confirmation for Product: " << productId << endl;
    }
};