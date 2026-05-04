#include <iostream>
#include "RoyalFlush.h"

#include <algorithm>
#include <vector>

// dummy helper
bool isRoyalFlush(const Hand& hand){
    if (hand.cards.size() != 5) return false;
    
    // Check Flush
    char suit = hand.cards[0].suit;
    for (const auto& card : hand.cards) if (card.suit != suit) return false;

    // Check Ranks (10, J, Q, K, A)
    std::vector<int> ranks;
    for (const auto& card : hand.cards) ranks.push_back(card.rank);
    std::sort(ranks.begin(), ranks.end());
    
    return ranks[0] == 10 && ranks[1] == 11 && ranks[2] == 12 && ranks[3] == 13 && ranks[4] == 14;
}
HandRank RoyalFlushChecker::check(const Hand& hand){
if (isRoyalFlush(hand)){
std::cout << "Detected Royal Flush\n";
return HandRank::Royal_Flush;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}