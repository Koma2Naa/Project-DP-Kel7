#pragma once
#include "PokerHandChecker.h"
class FourKindChecker : public PokerHandChecker{
public:
HandRank check(const Hand& hand) override;
};