#pragma once
#include "SkipCommand.h"

class FreeJokerSkipCommand : public SkipCommand {
public:
    std::string getDescription() const override;
    void execute(GameManager& gm) override;
};
