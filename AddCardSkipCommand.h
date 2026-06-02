#pragma once
#include "SkipCommand.h"

class AddCardSkipCommand : public SkipCommand {
public:
    std::string getDescription() const override;
    void execute(GameManager& gm) override;
};
