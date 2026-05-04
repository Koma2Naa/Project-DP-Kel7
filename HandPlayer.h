#pragma once
#include "Hand.h"

class HandPlayer {
public:
    // Menerima hand dari generator, dan mengembalikan hand yang sudah dipilih player
    Hand playHand(const Hand& generatedHand);
};