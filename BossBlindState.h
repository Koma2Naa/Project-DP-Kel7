#pragma once
#include "BlindState.h"

class BossBlindState : public BlindState {
public:
    std::string getName() const override;
    int getTargetScore(int ante) const override;
    int getRewardMoney() const override;
    std::unique_ptr<BlindState> nextState(int& ante) const override;
};