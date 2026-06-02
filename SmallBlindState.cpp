#include "SmallBlindState.h"
#include "BigBlindState.h"
#include "MoneySkipStrategy.h"

SmallBlindState::SmallBlindState() {
    skipStrategy = std::make_unique<MoneySkipStrategy>();
}

std::string SmallBlindState::getName() const { return "Small Blind"; }
int SmallBlindState::getTargetScore(int ante) const { return 5 * ante; }
int SmallBlindState::getRewardMoney() const { return 3; }

std::unique_ptr<BlindState> SmallBlindState::nextState(int& ante) const {
    return std::make_unique<BigBlindState>();
}

SkipStrategy* SmallBlindState::getSkipStrategy() const {
    return skipStrategy.get();
}