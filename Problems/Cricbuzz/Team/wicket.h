#pragma once
#include "../Inning/ballDetails.h"
#include "../Inning/overDetails.h"
#include "./Player/playerDetails.h"
#include "wicketType.h"

class Wicket {
public:
    WicketType wicketType;
    PlayerDetails* takenBy;
    OverDetails* overDetail;
    BallDetails* ballDetail;

    Wicket(WicketType wicketType, PlayerDetails* takenBy, OverDetails* overDetail, BallDetails* ballDetail) : 
    wicketType(wicketType), takenBy(takenBy), overDetail(overDetail), ballDetail(ballDetail) {}
};