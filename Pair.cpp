#include <iostream>
#include "Pair.h"

#include <map>

// dummy helper
bool isPair(const Hand& hand){
    if (hand.cards.size() < 2) return false;
    std::map<int, int> counts;
    for (const auto& card : hand.cards) counts[card.rank]++;
    for (auto const& [rank, count] : counts) if (count >= 2) return true;
    return false;
}
HandRank PairChecker::check(const Hand& hand){
if (isPair(hand)){
std::cout << "Detected PAIR\n";
return HandRank::PAIR;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}