#include "Deck.h"
#include <iostream>

Deck::Deck() {
    reset();
}

void Deck::reset() {
    cards.clear();
    discardPile.clear();
    char suits[] = {'H', 'D', 'C', 'S'};
    for (char suit : suits) {
        for (int rank = 2; rank <= 14; ++rank) {
            cards.push_back({rank, suit});
        }
    }
}

void Deck::discard(const std::vector<Card>& playedCards) {
    for (const auto& card : playedCards) {
        discardPile.push_back(card);
    }
}

void Deck::addCard(Card card) {
    cards.push_back(card);
}

void Deck::addCards(const std::vector<Card>& newCards) {
    for (const auto& card : newCards) {
        cards.push_back(card);
    }
}
