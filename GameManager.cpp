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
        
        deck.reset(); 
        handGenerator.shuffleDeck(deck); // Use HandGenerator for shuffling
        remainingHands = maxHands; 
        int accumulatedScore = 0;
        bool blindWon = false;

        // Start with a full hand of 8 cards
        Hand playerHand;
        playerHand.cards = handGenerator.drawCards(deck, 8); // Use HandGenerator for drawing

        while (remainingHands > 0 && !blindWon) {
            cout << "-------------------------\n";
            cout << "Remaining Hands: " << remainingHands << "\n";
            cout << "Current Score: " << accumulatedScore << " / " << targetScore << "\n";
            cout << "-------------------------\n";

            Hand chosenHand = handPlayer.playHand(playerHand);
            
            // Remove chosen cards from player's hand and discard them
            for (const auto& chosenCard : chosenHand.cards) {
                for (auto it = playerHand.cards.begin(); it != playerHand.cards.end(); ++it) {
                    if (it->rank == chosenCard.rank && it->suit == chosenCard.suit) {
                        playerHand.cards.erase(it);
                        break;
                    }
                }
            }
            deck.discard(chosenHand.cards);

            ScoreResult result = scoringRule.scoreHand(chosenHand);
            accumulatedScore += result.getTotal();
            remainingHands--;

            if (blindRule.isBlindDefeated(accumulatedScore, targetScore)) {
                blindWon = true;
            } else if (remainingHands == 0) {
                break;
            } else {
                cout << "\nScore increased! Need " << (targetScore - accumulatedScore) << " more.\n";
                // Refill hand up to 8 cards
                int cardsToDraw = 8 - playerHand.cards.size();
                std::vector<Card> newCards = handGenerator.drawCards(deck, cardsToDraw); // Use HandGenerator for refilling
                for (const auto& c : newCards) playerHand.cards.push_back(c);
                cout << "Drew " << newCards.size() << " cards from deck.\n";
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