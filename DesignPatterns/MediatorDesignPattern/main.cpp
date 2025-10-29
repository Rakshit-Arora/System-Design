#include <iostream>
#include "auctionHouse.h"
#include "colleague.h"
#include "bidder.h"
using namespace std;

int main() {
    cout << "Auction Demo implementing Mediator Design Pattern" << endl;

    AuctionMediator* auctionHouse = new AuctionHouse("vintage Guitar", 100.0);

    Colleague* alice = new Bidder("Alice", auctionHouse);
    Colleague* bob = new Bidder("Bob", auctionHouse);
    Colleague* charlie = new Bidder("Charlie", auctionHouse);

    alice->placeBid(150.0);
    bob -> placeBid(250.0);
    charlie->placeBid(300.0);
    alice->placeBid(300.0);
    bob->placeBid(500.0);

    auctionHouse->closeAuction();
}