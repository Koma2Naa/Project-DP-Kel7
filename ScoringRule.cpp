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

ScoreResult ScoringRule::scoreHand(const Hand &hand){
cout << "Calculating hand score...\n";
HandRank rank = Flushfivechecker.check(hand);
ScoreResult result = convertRankToScore(rank);
cout << "Hand Score: " << result.chips << " x " << result.multiplier << " = " << result.getTotal() << "\n";
return result;
}

ScoreResult ScoringRule::convertRankToScore(HandRank rank){
    switch (rank){
    case HandRank::HIGH_CARD:
        return {5, 1};
    case HandRank::PAIR:
        return {10, 2};
    case HandRank::TWO_PAIR:
        return {20, 2};
    case HandRank::THREE_OF_A_KIND:
        return {30, 3};
    case HandRank::STRAIGHT:
        return {30, 4};
    case HandRank::FLUSH:
        return {35, 4};
    case HandRank::FULL_HOUSE:
        return {40, 4};
    case HandRank::Four_of_a_Kind:
        return {60, 7};
    case HandRank::Straight_Flush:
        return {100, 8};
    case HandRank::Royal_Flush:
        return {120, 10};
    case HandRank::Five_of_a_Kind:
        return {120, 12};
    case HandRank::Flush_House:
        return {140, 14};
    case HandRank::Flush_Five:
        return {160, 16};
    default:
        return {0, 0};
    }
}