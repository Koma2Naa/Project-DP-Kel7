#include <iostream>
#include "Flush.h"

bool isFlush(const Hand& hand){
    if (hand.cards.size() < 5) return false;
    char suit = hand.cards[0].suit;
    for (const auto& card : hand.cards) if (card.suit != suit) return false;
    return true;
}
HandRank FlushChecker::check(const Hand& hand){
if (isFlush(hand)){
std::cout << "Detected FLUSH\n";
return HandRank::FLUSH;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}