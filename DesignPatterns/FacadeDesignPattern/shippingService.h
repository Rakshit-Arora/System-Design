#pragma once
#include <iostream>
using namespace std;

class ShippingService{
public:
    void shipProducts(string productId) {
        cout << "Your order has been shipped, will reach soon to your doorstep with productId: "
        << productId << endl;
    }
};