#include <iostream>
#include "FlushFive.h"

// dummy helper
bool isFlushFive(const Hand& hand){
return hand.value == 13;
}
HandRank FlushFiveChecker::check(const Hand& hand){
if (isFlushFive(hand)){
std::cout << "Detected Flush Five\n";
return HandRank::Flush_Five;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}