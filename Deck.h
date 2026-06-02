#pragma once
#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();
    void reset();           // Resets to full 52 cards
    void recollect();       // Returns discard pile to the deck
    void discard(const std::vector<Card>& cards);
    void addCard(Card card);
    void addCards(const std::vector<Card>& newCards);
    
    std::vector<Card>& getCards() { return cards; }
    std::vector<Card>& getDiscardPile() { return discardPile; }
    int remainingCards() const { return cards.size(); }

private:
    std::vector<Card> cards;
    std::vector<Card> discardPile;
};
