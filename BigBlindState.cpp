#include "BigBlindState.h"
#include "BossBlindState.h"
#include "SkipStrategyFactory.h"

BigBlindState::BigBlindState() {
    skipStrategy = SkipStrategyFactory::getRandomStrategy();
}

std::string BigBlindState::getName() const { return "Big Blind"; }
int BigBlindState::getTargetScore(int ante) const { return 20 * ante; }
int BigBlindState::getRewardMoney() const { return 4; }

std::unique_ptr<BlindState> BigBlindState::nextState(int& ante) const {
    return std::make_unique<BossBlindState>();
}

SkipStrategy* BigBlindState::getSkipStrategy() const {
    return skipStrategy.get();
}