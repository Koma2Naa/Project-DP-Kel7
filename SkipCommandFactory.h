#pragma once
#include <memory>
#include "SkipCommand.h"

class SkipCommandFactory {
public:
    static std::unique_ptr<SkipCommand> getRandomCommand();
};
