#pragma once
#include "Joker.h"
#include <iostream>

class ChipJoker : public Joker {
public:
    ChipJoker() : Joker("Chip Joker", 2) {}

    void applyScoreBonus(const Hand& hand, ScoreResult& currentScore) override {
        currentScore.chips += 10;
        std::cout << "[Joker] Chip Joker applied (+10 Chips)\n";
    }
};
