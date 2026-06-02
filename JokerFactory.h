#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Joker.h"

class JokerFactory {
public:
    static std::vector<std::unique_ptr<Joker>> generateFullJokerPool();
    static std::unique_ptr<Joker> getRandomJoker(const std::vector<std::string>& ownedNames);
};
