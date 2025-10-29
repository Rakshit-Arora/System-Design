#pragma once
#include "colleague.h"
#include <memory>
using namespace std;

class AuctionMediator {
public: 
    virtual ~AuctionMediator() = default;
    virtual void registerBidder(Colleague* bidder) = 0;
    virtual void placeBid(Colleague* bidder, double bidAmount) = 0;
    virtual void closeAuction() = 0;
};