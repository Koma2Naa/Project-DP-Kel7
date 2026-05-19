#include <iostream>
#include "BossBlindState.h"
#include "SmallBlindState.h"

std::string BossBlindState::getName() const { return "Boss Blind"; }
int BossBlindState::getTargetScore(int ante) const { return 40 * ante; }
int BossBlindState::getRewardMoney() const { return 5; }

std::unique_ptr<BlindState> BossBlindState::nextState(int& ante) const {
    ante++;
    std::cout << "=== BOSS DEFEATED ===\n";
    std::cout << "Ante increased to " << ante << "!\n";
    std::cout << "Cycle reset. Next: Small Blind.\n";
    return std::make_unique<SmallBlindState>();
}