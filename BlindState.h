#pragma once
#include <string>
#include <memory>
#include "SkipCommand.h"

class BlindState {
public:
    virtual ~BlindState() = default;
    virtual std::string getName() const = 0;
    virtual int getTargetScore(int ante) const = 0;
    virtual int getRewardMoney() const = 0;
    virtual std::unique_ptr<BlindState> nextState(int& ante) const = 0;
    
    // Optional skip command (null means cannot be skipped)
    virtual SkipCommand* getSkipCommand() const { return nullptr; }
};