#pragma once
#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "RewardRule.h"
#include "Shop.h"
#include "BlindState.h"
#include <memory>

class GameManager{
    public:
        GameManager();
        void runSession();
    private:
        HandGenerator handGenerator;
        HandPlayer handPlayer;
        ScoringRule scoringRule;
        RewardRule rewardRule; // Akan disesuaikan jika diperlukan nanti
        Shop shop;
        int playerMoney = 0;
        
        // Hands management
        int maxHands = 4; 
        int remainingHands = 0;

        std::unique_ptr<BlindState> currentBlind;
        int currentAnte;
};