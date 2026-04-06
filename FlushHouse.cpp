#include <iostream>
#include "FlushHouse.h"

// dummy helper
bool isFlushHouse(const Hand& hand){
return hand.value == 12;
}
HandRank FlushHouseChecker::check(const Hand& hand){
if (isFlushHouse(hand)){
std::cout << "Detected Flush House\n";
return HandRank::Flush_House;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}