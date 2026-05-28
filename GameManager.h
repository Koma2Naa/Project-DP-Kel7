#pragma once
#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "RewardRule.h"
#include "BlindRule.h"
#include "Shop.h"
#include "BlindState.h"
#include "Deck.h"
#include <memory>

class GameManager{
    public:
        GameManager();
        void runSession();
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
};