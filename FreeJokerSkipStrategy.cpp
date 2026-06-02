#include "FreeJokerSkipStrategy.h"
#include "GameManager.h"
#include "JokerFactory.h"
#include <iostream>

std::string FreeJokerSkipStrategy::getDescription() const {
    return "Make 1 Joker in the next shop free";
}

void FreeJokerSkipStrategy::apply(GameManager& gm) {
    gm.addPendingFreeShopJoker();
    std::cout << "[SKIP] Applied Free Shop Joker Tag! (Pending: " << gm.getPendingFreeShopJokers() << ")\n";
}
