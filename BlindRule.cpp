#include "BlindRule.h"

bool BlindRule::isBlindDefeated(int currentScore, int targetScore) {
    return currentScore >= targetScore;
}
