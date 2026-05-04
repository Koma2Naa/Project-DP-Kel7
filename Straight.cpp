#include <iostream>
#include "Straight.h"

#include <algorithm>
#include <vector>

// dummy helper
bool isStraight(const Hand& hand){
    if (hand.cards.size() < 5) return false;
    std::vector<int> ranks;
    for (const auto& card : hand.cards) ranks.push_back(card.rank);
    std::sort(ranks.begin(), ranks.end());
    ranks.erase(std::unique(ranks.begin(), ranks.end()), ranks.end());
    if (ranks.size() < 5) return false;

    // Check for 5 consecutive
    for (size_t i = 0; i <= ranks.size() - 5; i++) {
        if (ranks[i+4] == ranks[i] + 4) return true;
        // Special case: A-2-3-4-5
        if (ranks[i] == 2 && ranks[i+1] == 3 && ranks[i+2] == 4 && ranks[i+3] == 5 && ranks.back() == 14) return true;
    }
    return false;
}
HandRank StraightChecker::check(const Hand& hand){
if (isStraight(hand)){
std::cout << "Detected STRAIGHT\n";
return HandRank::STRAIGHT;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}