#include "FreeJokerSkipCommand.h"
#include "GameManager.h"
#include <iostream>

std::string FreeJokerSkipCommand::getDescription() const {
    return "Next shop Joker is FREE";
}

void FreeJokerSkipCommand::execute(GameManager& gm) {
    gm.addPendingFreeShopJoker();
    std::cout << "[TAG] Free Joker Tag applied: Your next shop Joker will be $0\n";
}
