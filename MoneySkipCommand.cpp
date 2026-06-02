#include "MoneySkipCommand.h"
#include "GameManager.h"
#include <iostream>

std::string MoneySkipCommand::getDescription() const {
    return "Gain $25 instantly";
}

void MoneySkipCommand::execute(GameManager& gm) {
    gm.addMoney(25);
    std::cout << "[TAG] Money Tag applied: +$25\n";
}
