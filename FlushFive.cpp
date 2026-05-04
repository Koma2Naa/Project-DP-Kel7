#include <iostream>
#include "FlushFive.h"
#include <algorithm>
#include <set>

bool isFlushFive(const Hand& hand){
    if (hand.cards.size() != 5) return false;
    
    // Check if all cards have the same suit
    char suit = hand.cards[0].suit;
    for (const auto& card : hand.cards) {
        if (card.suit != suit) return false;
    }
    
    // Check if ranks are consecutive
    std::vector<int> ranks;
    for (const auto& card : hand.cards) {
        ranks.push_back(card.rank);
    }
    std::sort(ranks.begin(), ranks.end());
    
    // Check for consecutive sequence (including A-2-3-4-5 as a special case)
    bool isConsecutive = true;
    for (size_t i = 1; i < ranks.size(); i++) {
        if (ranks[i] != ranks[i-1] + 1) {
            isConsecutive = false;
            break;
        }
    }
    
    // Special case: A-2-3-4-5 (wheel)
    if (!isConsecutive && ranks[0] == 2 && ranks[1] == 3 && ranks[2] == 4 && ranks[3] == 5 && ranks[4] == 14) {
        isConsecutive = true;
    }
    
    return isConsecutive;
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