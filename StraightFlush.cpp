#include <iostream>
#include "StraightFlush.h"

// dummy helper
bool isStraightFlush(const Hand& hand){
return hand.value == 9;
}
HandRank StraightFlushChecker::check(const Hand& hand){
if (isStraightFlush(hand)){
std::cout << "Detected Straight Flush\n";
return HandRank::Straight_Flush;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}