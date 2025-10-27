#pragma once
#include "inventoryService.h"
#include "paymentService.h"
#include "shippingService.h"
#include "notificationService.h"
using namespace std;

class OrderFacade {
private:
    InventoryService inventory;
    PaymentService payment;
    ShippingService shipping;
    NotificationService notification;

public:

    void placeOrder(string productId, string paymentMethod) {
        cout<<"Placing order for product: " << productId << endl;

        // check stock
        if(!inventory.checkStorage(productId)) {
            cout<<"Product out of stock" << endl;
            return;
        }

        // Make Payment
        if(!payment.makePayment(paymentMethod)) {
            cout<<"Payment failed"<<endl;
            return;
        }

        //Ship Product
        shipping.shipProducts(productId);

        //Send Notification
        notification.sendConfirmation(productId);

        cout<<"Order placed Successfully"<<endl;
    }
};