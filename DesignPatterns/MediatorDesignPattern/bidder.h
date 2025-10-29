#pragma once
#include "auctionMediator.h"
#include "colleague.h"
#include <string>
#include <memory>
#include <iostream>
using namespace std;

class Bidder : public Colleague {
public:
    string name;
    AuctionMediator* mediator;

    Bidder(string name, AuctionMediator* mediator) : name(name), mediator(mediator) {
        mediator -> registerBidder(this);
    }

    void placeBid(double amount) override {
        cout<<"[Placing Bid] " << name << " is attempting to bid $" << amount << endl;

    }

    void receiveBidNotification(double bidAmount) override {
        cout<<"[+] Bidder " << name << " has receive a new bid notification of: " << bidAmount << endl;
    }

    string getName() override {
        return name;
    }
};