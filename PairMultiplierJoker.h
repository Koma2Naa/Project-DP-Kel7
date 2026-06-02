#pragma once
#include "Joker.h"
#include <iostream>

class PairMultiplierJoker : public Joker {
public:
    PairMultiplierJoker() : Joker("Pair Multiplier Joker", 8), persistentMultiplier(0) {}

    void applyScoreBonus(const Hand& hand, ScoreResult& currentScore) override {
        if (currentScore.rank == HandRank::PAIR) {
            persistentMultiplier += 1;
            std::cout << "[Joker] Pair Multiplier Joker bonus increased! Current bonus: +" << persistentMultiplier << " Multiplier\n";
        }
        
        if (persistentMultiplier > 0) {
            currentScore.multiplier += persistentMultiplier;
            std::cout << "[Joker] Pair Multiplier Joker applied (+" << persistentMultiplier << " Multiplier)\n";
        }
    }

private:
    int persistentMultiplier;
};
