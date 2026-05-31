#pragma once
#include "Joker.h"
#include <iostream>

class MultiJoker : public Joker {
public:
    MultiJoker() : Joker("Multi Joker", 4) {}

    void applyScoreBonus(const Hand& hand, ScoreResult& currentScore) override {
        currentScore.multiplier += 10;
        std::cout << "[Joker] Multi Joker applied (+10 Multiplier)\n";
    }
};
