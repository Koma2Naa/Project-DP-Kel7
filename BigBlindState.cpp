#include "BigBlindState.h"
#include "BossBlindState.h"
#include "SkipCommandFactory.h"

BigBlindState::BigBlindState() {
    skipCommand = SkipCommandFactory::getRandomCommand();
}

std::string BigBlindState::getName() const { return "Big Blind"; }
int BigBlindState::getTargetScore(int ante) const { return 20 * ante; }
int BigBlindState::getRewardMoney() const { return 4; }

std::unique_ptr<BlindState> BigBlindState::nextState(int& ante) const {
    return std::make_unique<BossBlindState>();
}

SkipCommand* BigBlindState::getSkipCommand() const {
    return skipCommand.get();
}