#pragma once
#include "card.h"
using namespace std;

class User {
public: 
    Card* card;

    void setCard(Card* c) {
        card = c;
    }
};