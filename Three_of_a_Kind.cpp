#include <iostream>
#include "Three_of_a_Kind.h"

#include <map>

// dummy helper
bool isThreeKind(const Hand& hand){
    if (hand.cards.size() < 3) return false;
    std::map<int, int> counts;
    for (const auto& card : hand.cards) counts[card.rank]++;
    for (auto const& [rank, count] : counts) if (count >= 3) return true;
    return false;
}
HandRank ThreeKindChecker::check(const Hand& hand){
if (isThreeKind(hand)){
std::cout << "Detected Three of a Kind\n";
return HandRank::THREE_OF_A_KIND;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}