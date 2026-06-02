#pragma once
#include <string>
#include <memory>
#include "SkipStrategy.h"

class BlindState {
public:
    virtual ~BlindState() = default;
    virtual std::string getName() const = 0;
    virtual int getTargetScore(int ante) const = 0;
    virtual int getRewardMoney() const = 0;
    virtual std::unique_ptr<BlindState> nextState(int& ante) const = 0;
    
    // Optional skip strategy (null means cannot be skipped)
    virtual SkipStrategy* getSkipStrategy() const { return nullptr; }
};