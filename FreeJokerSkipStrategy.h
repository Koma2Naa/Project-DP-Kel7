#pragma once
#include "SkipStrategy.h"

class FreeJokerSkipStrategy : public SkipStrategy {
public:
    std::string getDescription() const override;
    void apply(GameManager& gm) override;
};
