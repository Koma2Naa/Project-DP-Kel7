#pragma once
#include "Hand.h"

enum class HandRank{
    HIGH_CARD,
    PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    Four_of_a_Kind,
    Straight_Flush,
    Royal_Flush,
    Five_of_a_Kind,
    Flush_House,
    Flush_Five
};

class PokerHandChecker
{
public:
    virtual HandRank check(const Hand &hand) = 0;
    void setNext(PokerHandChecker *next);

protected:
    PokerHandChecker *nextChecker = nullptr;
};