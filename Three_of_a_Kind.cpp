#include <iostream>
#include "Three_of_a_Kind.h"

// dummy helper
bool isThreeKind(const Hand& hand){
return hand.value == 4;
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