#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "auctionMediator.h"
#include "colleague.h"
using namespace std;

class AuctionHouse : public AuctionMediator {
private:
    vector<Colleague*> bidders;
    string itemName;
    double currentHighestBid;
    Colleague* currentHighestBidder = nullptr;

public:
    AuctionHouse(const string& itemName, double startingPrice)
        : itemName(itemName), currentHighestBid(startingPrice) {
        cout << "[+] Auction House created for item: " << itemName << " with initial bid of $" << startingPrice << endl;
    }

    void registerBidder(Colleague* bidder) override {
        bidders.push_back(bidder);
        cout << "[+] " << bidder->getName() << " has joined the auction for " << itemName << endl;
    }

    void placeBid(Colleague* bidder, double bidAmount) override {
        if (bidAmount <= currentHighestBid) {
            cout << bidder->getName() << " bid of $" << bidAmount << " is too low. Current highest bid is $" << currentHighestBid << endl;
            return;
        }

        // Update highest bid
        currentHighestBid = bidAmount;
        currentHighestBidder = bidder;

        cout << "\n===> [New Bid Accepted]" << " Info: {Bidder: " << bidder->getName()
        << ", Bid Amount: $" << bidAmount << "}" << endl;

        // Notify other bidders
        for (auto* colleague : bidders) {
            if (colleague->getName() != bidder->getName()) {
                colleague->receiveBidNotification(bidAmount);
            }
        }
    }

    void closeAuction() override {
        cout << "\n===> [AUCTION UPDATE]" << endl;
        if (currentHighestBidder != nullptr) {
            cout << "[+] Auction closed! Winner is " << currentHighestBidder->getName()
            << " with a bid of $" << currentHighestBid << " for " << itemName << endl;
        } 
        else {
            cout << "Auction closed with no bids." << endl;
        }
    }
};
