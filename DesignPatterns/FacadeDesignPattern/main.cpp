#include "orderFacade.h"
#include <iostream>
using namespace std;

int main() {
    cout<<"----- Facade Desing Pattern Demo ------"<<endl;

    OrderFacade order;

    //Place first order;
    order.placeOrder("Macbook Pro", "Credit Card");

    //Place another order
    order.placeOrder("Cricket Bat", "UPI");
}