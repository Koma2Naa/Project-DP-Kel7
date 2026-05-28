#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "HandGenerator.h"
using namespace std;

void HandGenerator::shuffleDeck(Deck& deck) {
    cout << "Mengacak deck...\n";
    vector<Card>& cards = deck.getCards();
    random_device rd;
    mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
}

vector<Card> HandGenerator::drawCards(Deck& deck, int count) {
    vector<Card>& cards = deck.getCards();
    vector<Card> drawn;
    for (int i = 0; i < count && !cards.empty(); ++i) {
        drawn.push_back(cards.back());
        cards.pop_back();
    }
    return drawn;
}