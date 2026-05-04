#include <iostream>
#include "StraightFlush.h"

#include <algorithm>
#include <vector>

// dummy helper
bool isStraightFlush(const Hand& hand){
    if (hand.cards.size() < 5) return false;
    
    // Check Flush
    char suit = hand.cards[0].suit;
    for (const auto& card : hand.cards) if (card.suit != suit) return false;

    // Check Straight
    std::vector<int> ranks;
    for (const auto& card : hand.cards) ranks.push_back(card.rank);
    std::sort(ranks.begin(), ranks.end());
    
    bool isConsecutive = true;
    for (size_t i = 1; i < ranks.size(); i++) {
        if (ranks[i] != ranks[i-1] + 1) {
            isConsecutive = false;
            break;
        }
    }
    if (isConsecutive) return true;

    // Special case: A-2-3-4-5
    if (ranks.size() == 5 && ranks[0] == 2 && ranks[1] == 3 && ranks[2] == 4 && ranks[3] == 5 && ranks[4] == 14) return true;

    return false;
}
HandRank StraightFlushChecker::check(const Hand& hand){
if (isStraightFlush(hand)){
std::cout << "Detected Straight Flush\n";
return HandRank::Straight_Flush;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}