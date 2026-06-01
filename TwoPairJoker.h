#pragma once
#include "Joker.h"
#include <iostream>

class TwoPairJoker : public Joker {
public:
    TwoPairJoker() : Joker("Two Pair Joker", 10) {}

    void applyScoreBonus(const Hand& hand, ScoreResult& currentScore) override {
        if (currentScore.rank == HandRank::TWO_PAIR) {
            currentScore.chips += 10;
            std::cout << "[Joker] Two Pair Joker applied (+10 Chips)\n";
        }
    }
};
