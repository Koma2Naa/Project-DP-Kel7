#include <iostream>
#include "GameManager.h"
using namespace std;

void GameManager::runSession(){
    cout << "=== Run Started ===\n";
    Hand hand = handGenerator.generateHand();
    Hand chosenHand = handPlayer.playHand(hand);
    int score = scoringRule.scoreHand(chosenHand);
    bool win = blindRule.checkBlind(score);

    int reward = rewardRule.earnMoney(win, score);
    cout << "Money gained: " << reward << "\n";
    playerMoney += reward;

    shop.rerollShop();
    shop.enterShop(playerMoney);

    cout << "=== Run Ended ===\n";
}