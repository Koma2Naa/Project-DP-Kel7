#pragma once
#include "Hand.h"

struct ScoreResult {
    int chips;
    int multiplier;
    HandRank rank;

    int getTotal() const { return chips * multiplier; }
};
