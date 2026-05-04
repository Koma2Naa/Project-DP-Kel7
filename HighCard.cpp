#include <iostream>
#include "HighCard.h"
using namespace std;

HandRank HighCardChecker::check(const Hand& hand){
    cout << "Detected HIGH CARD\n";
    return HandRank::HIGH_CARD;
}