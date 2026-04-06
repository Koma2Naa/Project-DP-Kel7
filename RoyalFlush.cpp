#include <iostream>
#include "RoyalFlush.h"

// dummy helper
bool isRoyalFlush(const Hand& hand){
return hand.value == 10;
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