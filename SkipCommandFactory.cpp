#include "SkipCommandFactory.h"
#include "MoneySkipCommand.h"
#include "FreeJokerSkipCommand.h"
#include "ExtraHandSkipCommand.h"
#include "AddCardSkipCommand.h"
#include <vector>
#include <random>

std::unique_ptr<SkipCommand> SkipCommandFactory::getRandomCommand() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> dis(0, 3);

    int choice = dis(g);
    switch (choice) {
        case 0: return std::make_unique<MoneySkipCommand>();
        case 1: return std::make_unique<FreeJokerSkipCommand>();
        case 2: return std::make_unique<ExtraHandSkipCommand>();
        case 3: return std::make_unique<AddCardSkipCommand>();
        default: return std::make_unique<MoneySkipCommand>();
    }
}
