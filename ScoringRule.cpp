#include <iostream>
#include "ScoringRule.h"
using namespace std;

ScoringRule::ScoringRule(){
    Flushfivechecker.setNext(&Flushhousechecker);
    Flushhousechecker.setNext(&Fivekindchecker);
    Fivekindchecker.setNext(&Royalflushchecker);
    Royalflushchecker.setNext(&Straightflushfhecker);
    Straightflushfhecker.setNext(&Fourkindchecker);
    Fourkindchecker.setNext(&Fullhousechecker);
    Fullhousechecker.setNext(&Flushchecker);
    Flushchecker.setNext(&Straightchecker);
    Straightchecker.setNext(&Threekindchecker);
    Threekindchecker.setNext(&Twopairchecker);
    Twopairchecker.setNext(&Pairchecker);
    Pairchecker.setNext(&Highcardchecker);
}

int ScoringRule::scoreHand(const Hand &hand){
cout << "Calculating hand score...\n";
HandRank rank = Flushfivechecker.check(hand);
int score = convertRankToScore(rank);
cout << "Final score = " << score << "\n";
return score;
}

int ScoringRule::convertRankToScore(HandRank rank){
    switch (rank){
    case HandRank::HIGH_CARD:
        return 1;
    case HandRank::PAIR:
        return 10;
    case HandRank::TWO_PAIR:
        return 20;
    case HandRank::THREE_OF_A_KIND:
        return 30;
    case HandRank::STRAIGHT:
        return 40;
    case HandRank::FLUSH:
        return 50;
    case HandRank::FULL_HOUSE:
        return 60;
    case HandRank::Four_of_a_Kind:
        return 70;
    case HandRank::Straight_Flush:
        return 80;
    case HandRank::Royal_Flush:
        return 90;
    case HandRank::Five_of_a_Kind:
        return 100;
    case HandRank::Flush_House:
        return 110;
    case HandRank::Flush_Five:
        return 120;
    default:
        return 0;
    }
}