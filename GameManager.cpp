#include <iostream>
#include "GameManager.h"
#include "SmallBlindState.h"
using namespace std;

GameManager::GameManager() : currentAnte(1) {
    currentBlind = make_unique<SmallBlindState>();
}

void GameManager::addJoker(std::unique_ptr<Joker> joker) {
    cout << "Added Joker to inventory: " << joker->getName() << "\n";
    activeJokers.push_back(std::move(joker));
}

std::vector<std::string> GameManager::getOwnedJokerNames() const {
    std::vector<std::string> names;
    for (const auto& j : activeJokers) {
        names.push_back(j->getName());
    }
    return names;
}

void GameManager::runSession(){
    cout << "=== Run Started ===\n";
    bool isPlaying = true;
    
    deck.reset(); // Standard reset only at the very start of a run

    while (isPlaying) {
        cout << "\n=== New Blind Started ===\n";
        cout << "Current Blind: " << currentBlind->getName() << " (Ante " << currentAnte << ")\n";
        int targetScore = currentBlind->getTargetScore(currentAnte);
        cout << "Target Score to Win: " << targetScore << "\n";
        cout << "Reward on Victory: $" << currentBlind->getRewardMoney() << "\n";
        
        // Skip Blind Info Display
        SkipStrategy* skipStrat = currentBlind->getSkipStrategy();
        if (skipStrat != nullptr) {
            cout << "Skip Reward: " << skipStrat->getDescription() << "\n";
        }

        // Skip Blind Prompt
        if (skipStrat != nullptr) {
            cout << "\n>>> [P]lay Blind or [S]kip? (P/S): ";
            string choice;
            getline(cin, choice);
            if (choice == "S" || choice == "s") {
                skipStrat->apply(*this);
                cout << "Skipping blind and moving to the next round...\n";
                currentBlind = currentBlind->nextState(currentAnte);
                continue; // Skip the rest of the loop (playing and shop)
            }
        }

        deck.recollect(); // Gather all discarded and hand cards back into the deck
        handGenerator.shuffleDeck(deck); // Use HandGenerator for shuffling
        remainingHands = maxHands; 
        int accumulatedScore = 0;
        bool blindWon = false;

        // Start with a full hand of 8 cards
        Hand playerHand;
        playerHand.cards = handGenerator.drawCards(deck, 8); // Use HandGenerator for drawing

        while (remainingHands > 0 && !blindWon) {
            cout << "-------------------------\n";
            displayActiveJokers();
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
            
            // Apply Joker bonuses
            for (auto& joker : activeJokers) {
                joker->applyScoreBonus(chosenHand, result);
            }
            if (!activeJokers.empty()) {
                cout << "Final Score after Jokers: " << result.chips << " x " << result.multiplier << " = " << result.getTotal() << "\n";
            }

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
            
            std::vector<std::string> ownedNames;
            for (const auto& j : activeJokers) {
                ownedNames.push_back(j->getName());
            }

            shop.rerollShop(ownedNames, pendingFreeShopJokers);
            auto boughtItems = shop.enterShop(playerMoney);
            for (auto& item : boughtItems) {
                Joker* jokerPtr = dynamic_cast<Joker*>(item.get());
                if (jokerPtr) {
                    // Release from the generic ShopItem unique_ptr and cast to Joker unique_ptr
                    std::unique_ptr<Joker> joker(static_cast<Joker*>(item.release()));
                    addJoker(std::move(joker));
                }
            }

            cout << "Leaving " << currentBlind->getName() << "...\n";
            currentBlind = currentBlind->nextState(currentAnte);
        } else {
            cout << "Result: LOSE! No hands remaining. Game Over.\n";
            isPlaying = false;
        }

        // Return any leftover cards in hand to the discard pile before the next round
        deck.discard(playerHand.cards);
    }
    
    cout << "=== Run Ended ===\n";
}

void GameManager::displayActiveJokers() const {
    cout << "Active Jokers: ";
    if (activeJokers.empty()) {
        cout << "(None)\n";
    } else {
        for (size_t i = 0; i < activeJokers.size(); ++i) {
            cout << "\n[" << activeJokers[i]->getName() << "]";
            if (i < activeJokers.size() - 1) cout << ", ";
        }
        cout << "\n";
    }
}