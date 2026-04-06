#include <iostream>
#include "FiveOf_aKind.h"

// dummy helper
bool isFiveKind(const Hand& hand){
return hand.value == 11;
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