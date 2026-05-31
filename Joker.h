#pragma once
#include "ShopItem.h"
#include "Hand.h"
#include "ScoreResult.h"

class Joker : public ShopItem {
public:
    Joker(std::string name, int price);
    virtual ~Joker() = default;

    // Hook: Called after base score calculation to allow Jokers to modify it.
    virtual void applyScoreBonus(const Hand& hand, ScoreResult& currentScore) {}

    // Implement onPurchase from ShopItem
    void onPurchase() override;
};
