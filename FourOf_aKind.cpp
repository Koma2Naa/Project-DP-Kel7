#include <iostream>
#include "FourOf_aKind.h"

// dummy helper
bool isFourKind(const Hand& hand){
return hand.value == 8;
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