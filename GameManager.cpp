#include <iostream>
#include "GameManager.h"
using namespace std;

void GameManager::runSession(){
    cout << "=== Run Started ===\n";
    Hand hand = handGenerator.generateHand();
    handPlayer.playHand(hand);
    int score = scoringRule.scoreHand(hand);
    bool win = blindRule.checkBlind(score);

    int reward = rewardRule.earnMoney(win, score);
    cout << "Money gained: " << reward << "\n";
    cout << "=== Run Ended ===\n";
}