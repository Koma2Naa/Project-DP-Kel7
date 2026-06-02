#include "SkipStrategyFactory.h"
#include "MoneySkipStrategy.h"
#include "FreeJokerSkipStrategy.h"
#include "ExtraHandSkipStrategy.h"
#include "AddCardSkipStrategy.h"
#include <vector>
#include <random>

std::unique_ptr<SkipStrategy> SkipStrategyFactory::getRandomStrategy() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> dis(0, 3);

    int choice = dis(g);
    switch (choice) {
        case 0: return std::make_unique<MoneySkipStrategy>();
        case 1: return std::make_unique<FreeJokerSkipStrategy>();
        case 2: return std::make_unique<ExtraHandSkipStrategy>();
        case 3: return std::make_unique<AddCardSkipStrategy>();
        default: return std::make_unique<MoneySkipStrategy>();
    }
}
