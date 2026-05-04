#include <iostream>
#include "FiveOf_aKind.h"

#include <map>

bool isFiveKind(const Hand& hand){
    if (hand.cards.size() != 5) return false;
    std::map<int, int> counts;
    for (const auto& card : hand.cards) counts[card.rank]++;
    return counts.size() == 1;
}
HandRank FiveKindChecker::check(const Hand& hand){
if (isFiveKind(hand)){
std::cout << "Detected Five of a Kind\n";
return HandRank::Five_of_a_Kind;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}