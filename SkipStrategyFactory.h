#pragma once
#include <memory>
#include "SkipStrategy.h"

class SkipStrategyFactory {
public:
    static std::unique_ptr<SkipStrategy> getRandomStrategy();
};
