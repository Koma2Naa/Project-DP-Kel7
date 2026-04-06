#include <iostream>
#include "GameManager.h"
using namespace std;

void GameManager::runSession(){
    cout << "=== Run Started ===\n";
    handGenerator.generateHand();
    handPlayer.playHand();
    int score = scoringRule.scoreHand();
    bool win = blindRule.checkBlind(score);

    int reward = rewardRule.earnMoney(win, score);
    cout << "Money gained: " << reward << "\n";
    cout << "=== Run Ended ===\n";
}