#include <iostream>
#include "FourOf_aKind.h"

#include <map>

// dummy helper
bool isFourKind(const Hand& hand){
    if (hand.cards.size() < 4) return false;
    std::map<int, int> counts;
    for (const auto& card : hand.cards) counts[card.rank]++;
    for (auto const& [rank, count] : counts) if (count >= 4) return true;
    return false;
}
HandRank FourKindChecker::check(const Hand& hand){
if (isFourKind(hand)){
std::cout << "Detected Four of a Kind\n";
return HandRank::Four_of_a_Kind;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}