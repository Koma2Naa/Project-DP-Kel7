#include <iostream>
#include "FullHouse.h"
#include <map>

// dummy helper
bool isFullHouse(const Hand& hand){
    if (hand.cards.size() != 5) return false;
    std::map<int, int> counts;
    for (const auto& card : hand.cards) counts[card.rank]++;
    if (counts.size() != 2) return false;
    bool hasThree = false, hasTwo = false;
    for (auto const& [rank, count] : counts) {
        if (count == 3) hasThree = true;
        if (count == 2) hasTwo = true;
    }
    return hasThree && hasTwo;
}

HandRank FullHouseChecker::check(const Hand& hand){
    if (isFullHouse(hand)){
        std::cout << "Detected FULL HOUSE\n";
        return HandRank::FULL_HOUSE;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
