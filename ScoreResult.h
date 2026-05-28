#pragma once

struct ScoreResult {
    int chips;
    int multiplier;

    int getTotal() const { return chips * multiplier; }
};
