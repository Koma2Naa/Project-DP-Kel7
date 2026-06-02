#pragma once
#include "SkipStrategy.h"

class AddCardSkipStrategy : public SkipStrategy {
public:
    std::string getDescription() const override;
    void apply(GameManager& gm) override;
};
