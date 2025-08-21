#include "HeaderFile/customer.h"
#include "HeaderFile/stockItem.h"
using namespace std;

int main() {
    StockItem Laptop("Laptop", 0);  // Create stock item (starts with 0 = out of stock)

    // Create customers
    Customer Alice("Alice");
    Customer Bob("Bob");

    // Customers subscribe to stock notifications
    Laptop.add(&Alice);
    Laptop.add(&Bob);

    Laptop.restock(10); // Notify Alice and Bob that Laptop is back in stock
    Laptop.restock(5);  // Notify again, but no notification since it was already

    Laptop.remove(&Alice); // Alice is no longer interested

    Laptop.restock(-15); // force stock to 0, no notification since it was already out of stock

    Laptop.restock(20); // Notify Bob that Laptop is back in stock

    return 0;
}