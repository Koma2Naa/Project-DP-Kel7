#include "JokerFactory.h"
#include "ChipJoker.h"
#include "MultiJoker.h"
#include "FullHouseJoker.h"
#include "TwoPairJoker.h"
#include "PairMultiplierJoker.h"
#include <algorithm>
#include <random>

std::vector<std::unique_ptr<Joker>> JokerFactory::generateFullJokerPool() {
    std::vector<std::unique_ptr<Joker>> pool;
    pool.push_back(std::make_unique<MultiJoker>());
    pool.push_back(std::make_unique<ChipJoker>());
    pool.push_back(std::make_unique<FullHouseJoker>());
    pool.push_back(std::make_unique<TwoPairJoker>());
    pool.push_back(std::make_unique<PairMultiplierJoker>());
    return pool;
}

std::unique_ptr<Joker> JokerFactory::getRandomJoker(const std::vector<std::string>& ownedNames) {
    auto fullPool = generateFullJokerPool();
    std::vector<std::unique_ptr<Joker>> filteredPool;

    for (auto& joker : fullPool) {
        bool owned = false;
        for (const auto& name : ownedNames) {
            if (joker->getName() == name) {
                owned = true;
                break;
            }
        }
        if (!owned) {
            filteredPool.push_back(std::move(joker));
        }
    }

    if (filteredPool.empty()) return nullptr;

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(filteredPool.begin(), filteredPool.end(), g);

    return std::move(filteredPool[0]);
}
