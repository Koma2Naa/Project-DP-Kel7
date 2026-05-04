#include <iostream>
#include "FlushHouse.h"
#include <algorithm>
#include <map>

bool isFlushHouse(const Hand& hand){
    if (hand.cards.size() != 5) return false;
    
    // Check if all cards have the same suit
    char suit = hand.cards[0].suit;
    for (const auto& card : hand.cards) {
        if (card.suit != suit) return false;
    }
    
    // Check if it's a full house pattern (3 of one rank + 2 of another)
    std::map<int, int> rankCount;
    for (const auto& card : hand.cards) {
        rankCount[card.rank]++;
    }
    
    // Should have exactly 2 different ranks: one with count 3, one with count 2
    if (rankCount.size() != 2) return false;
    
    int count1 = rankCount.begin()->second;
    int count2 = rankCount.rbegin()->second;
    
    return (count1 == 3 && count2 == 2) || (count1 == 2 && count2 == 3);
}

HandRank FlushHouseChecker::check(const Hand& hand){
    if (isFlushHouse(hand)){
        std::cout << "Detected Flush House\n";
        return HandRank::Flush_House;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}