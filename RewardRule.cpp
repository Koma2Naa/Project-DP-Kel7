#include "RewardRule.h"
#include <algorithm>
#include <iostream>

int RewardRule::calculateTotalReward(bool win, int baseReward, int remainingHands, int playerMoney){
    if (!win) return 0;

    int handBonus = remainingHands; // $1 per unused hand
    int interest = std::min(5, playerMoney / 5); // $1 per $5, capped at $5

    std::cout << "\n--- Reward Breakdown ---\n";
    std::cout << "Base Reward:  $" << baseReward << "\n";
    std::cout << "Hand Bonus:   $" << handBonus << "\n";
    std::cout << "Interest:     $" << interest << "\n";
    
    int total = baseReward + handBonus + interest;
    std::cout << "Total Payout: $" << total << "\n";
    std::cout << "------------------------\n";
    
    return total;
}