#pragma once
#include "Hand.h"
#include "Deck.h"

class HandGenerator{
public:
    void shuffleDeck(Deck& deck);
    std::vector<Card> drawCards(Deck& deck, int count);
};