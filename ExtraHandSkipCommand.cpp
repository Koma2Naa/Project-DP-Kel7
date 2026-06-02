#include "ExtraHandSkipCommand.h"
#include "GameManager.h"

std::string ExtraHandSkipCommand::getDescription() const {
    return "Next Blind gives +1 Hand";
}

void ExtraHandSkipCommand::execute(GameManager& gm) {
    gm.addPendingExtraHands();
}
