#pragma once
#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "RewardRule.h"
#include "BlindRule.h"
#include "Shop.h"
#include "BlindState.h"
#include "Deck.h"
#include "Joker.h"
#include <memory>
#include <vector>

class GameManager{
    public:
        GameManager();
        void runSession();
        void addJoker(std::unique_ptr<Joker> joker);
        void displayActiveJokers() const;
        
        void addMoney(int amount) { playerMoney += amount; }
        int getMoney() const { return playerMoney; }
        std::vector<std::string> getOwnedJokerNames() const;

    private:
        HandGenerator handGenerator;
        HandPlayer handPlayer;
        ScoringRule scoringRule;
        RewardRule rewardRule;
        BlindRule blindRule;
        Shop shop;
        Deck deck;
        int playerMoney = 0;
        
        // Hands management
        int maxHands = 4; 
        int remainingHands = 0;

        std::unique_ptr<BlindState> currentBlind;
        int currentAnte;

        std::vector<std::unique_ptr<Joker>> activeJokers;
};