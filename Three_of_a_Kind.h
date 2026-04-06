#pragma once
#include "PokerHandChecker.h"
class ThreeKindChecker : public PokerHandChecker{
public:
HandRank check(const Hand& hand) override;
};