#pragma once
#include <string>

class GameManager;

class SkipStrategy {
public:
    virtual ~SkipStrategy() = default;
    virtual std::string getDescription() const = 0;
    virtual void apply(GameManager& gm) = 0;
};
