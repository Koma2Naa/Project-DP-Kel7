#include "MoneySkipStrategy.h"
#include "GameManager.h"
#include <iostream>

std::string MoneySkipStrategy::getDescription() const {
    return "Gain $10 immediately";
}

void MoneySkipStrategy::apply(GameManager& gm) {
    gm.addMoney(10);
    std::cout << "[SKIP] Applied Money Reward: +$10 (Total: $" << gm.getMoney() << ")\n";
}
