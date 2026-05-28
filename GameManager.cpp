#include <iostream>
#include "GameManager.h"
#include "SmallBlindState.h"
using namespace std;

GameManager::GameManager() : currentAnte(1) {
    currentBlind = make_unique<SmallBlindState>();
}

void GameManager::runSession(){
    cout << "=== Run Started ===\n";
    bool isPlaying = true;
    
    while (isPlaying) {
        cout << "\n=== New Blind Started ===\n";
        cout << "Current Blind: " << currentBlind->getName() << " (Ante " << currentAnte << ")\n";
        int targetScore = currentBlind->getTargetScore(currentAnte);
        cout << "Target Score to Win: " << targetScore << "\n";
        cout << "Reward on Victory: $" << currentBlind->getRewardMoney() << "\n";
        
        remainingHands = maxHands; 
        int accumulatedScore = 0;
        bool blindWon = false;

        while (remainingHands > 0 && !blindWon) {
            cout << "-------------------------\n";
            cout << "Remaining Hands: " << remainingHands << "\n";
            cout << "Current Score: " << accumulatedScore << " / " << targetScore << "\n";
            cout << "-------------------------\n";

            Hand hand = handGenerator.generateHand();
            Hand chosenHand = handPlayer.playHand(hand);
            int score = scoringRule.scoreHand(chosenHand);
            
            accumulatedScore += score;
            remainingHands--;

            if (blindRule.isBlindDefeated(accumulatedScore, targetScore)) {
                blindWon = true;
            } else if (remainingHands == 0) {
                break;
            } else {
                cout << "\nScore increased! Need " << (targetScore - accumulatedScore) << " more.\n";
            }
        }
        
        cout << "\nChecking blind requirement...\n";
        cout << "Final Score: " << accumulatedScore << " | Target: " << targetScore << "\n";
        
        if (blindWon) {
            cout << "Result: WIN! You have defeated the " << currentBlind->getName() << ".\n";
            
            int totalReward = rewardRule.calculateTotalReward(
                true, 
                currentBlind->getRewardMoney(), 
                remainingHands, 
                playerMoney
            );
            
            playerMoney += totalReward;
            
            shop.rerollShop();
            shop.enterShop(playerMoney);

            cout << "Leaving " << currentBlind->getName() << "...\n";
            currentBlind = currentBlind->nextState(currentAnte);
        } else {
            cout << "Result: LOSE! No hands remaining. Game Over.\n";
            isPlaying = false;
        }
    }
    
    cout << "=== Run Ended ===\n";
}