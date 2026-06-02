#pragma once
#include "BlindState.h"

class BigBlindState : public BlindState {
public:
    BigBlindState();
    std::string getName() const override;
    int getTargetScore(int ante) const override;
    int getRewardMoney() const override;
    std::unique_ptr<BlindState> nextState(int& ante) const override;
    SkipStrategy* getSkipStrategy() const override;

private:
    std::unique_ptr<SkipStrategy> skipStrategy;
};