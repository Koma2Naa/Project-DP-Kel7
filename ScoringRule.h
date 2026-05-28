#pragma once
#include "HighCard.h"
#include "Pair.h"
#include "TwoPair.h"
#include "Three_of_a_Kind.h"
#include "Straight.h"
#include "Flush.h"
#include "FullHouse.h"
#include "FourOf_aKind.h"
#include "StraightFlush.h"
#include "RoyalFlush.h"
#include "FiveOf_aKind.h"
#include "FlushHouse.h"
#include "FlushFive.h"
#include "ScoreResult.h"

class ScoringRule{
public:
    ScoringRule();
    ScoreResult scoreHand(const Hand &hand);
private:
    HighCardChecker Highcardchecker;
    PairChecker Pairchecker;
    TwoPairChecker Twopairchecker;
    ThreeKindChecker Threekindchecker;
    StraightChecker Straightchecker;
    FlushChecker Flushchecker;
    FullHouseChecker Fullhousechecker;
    FourKindChecker Fourkindchecker;
    StraightFlushChecker Straightflushfhecker;
    RoyalFlushChecker Royalflushchecker;
    FiveKindChecker Fivekindchecker;
    FlushHouseChecker Flushhousechecker;
    FlushFiveChecker Flushfivechecker;

    ScoreResult convertRankToScore(HandRank rank);
};
