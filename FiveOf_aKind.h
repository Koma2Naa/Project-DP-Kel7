#pragma once
#include "PokerHandChecker.h"
class FiveKindChecker : public PokerHandChecker{
public:
HandRank check(const Hand& hand) override;
};