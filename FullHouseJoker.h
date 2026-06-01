#pragma once
#include "Joker.h"
#include <iostream>

class FullHouseJoker : public Joker {
public:
    FullHouseJoker() : Joker("Full House Joker", 6) {}

    void applyScoreBonus(const Hand& hand, ScoreResult& currentScore) override {
        if (currentScore.rank == HandRank::FULL_HOUSE) {
            currentScore.multiplier += 20;
            std::cout << "[Joker] Full House Joker applied (+20 Multiplier)\n";
        }
    }
};
