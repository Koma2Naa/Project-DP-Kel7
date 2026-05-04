#include <iostream>
#include "FlushFive.h"
#include <algorithm>
#include <set>

bool isFlushFive(const Hand& hand){
    if (hand.cards.size() != 5) return false;
    char suit = hand.cards[0].suit;
    int rank = hand.cards[0].rank;
    for (const auto& card : hand.cards) {
        if (card.suit != suit || card.rank != rank) return false;
    }
    return true;
}

HandRank FlushFiveChecker::check(const Hand& hand){
    if (isFlushFive(hand)){
        std::cout << "Detected Flush Five\n";
        return HandRank::Flush_Five;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}