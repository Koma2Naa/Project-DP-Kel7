#include <iostream>
#include "TwoPair.h"

#include <map>

// dummy helper
bool isTwoPair(const Hand& hand){
    if (hand.cards.size() < 4) return false;
    std::map<int, int> counts;
    for (const auto& card : hand.cards) counts[card.rank]++;
    int pairs = 0;
    for (auto const& [rank, count] : counts) if (count >= 2) pairs++;
    return pairs >= 2;
}
HandRank TwoPairChecker::check(const Hand& hand){
if (isTwoPair(hand)){
std::cout << "Detected TWO PAIR\n";
return HandRank::TWO_PAIR;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}