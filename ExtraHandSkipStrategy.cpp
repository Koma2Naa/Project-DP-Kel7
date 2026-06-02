#include "ExtraHandSkipStrategy.h"
#include "GameManager.h"

std::string ExtraHandSkipStrategy::getDescription() const {
    return "Next Blind gives +1 Hand";
}

void ExtraHandSkipStrategy::apply(GameManager& gm) {
    gm.addPendingExtraHands();
}
