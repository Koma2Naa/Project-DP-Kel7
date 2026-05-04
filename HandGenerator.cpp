#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "HandGenerator.h"
using namespace std;

Hand HandGenerator::generateHand(){
    cout << "Mengacak dan membagikan kartu...\n";
    
    // Membuat deck standar 52 kartu
    vector<Card> deck;
    char suits[] = {'H', 'D', 'C', 'S'}; // Hearts, Diamonds, Clubs, Spades
    for (char suit : suits) {
        for (int rank = 2; rank <= 14; ++rank) { // Rank 2 sampai 14 (As)
            deck.push_back({rank, suit});
        }
    }

    // Mengacak deck (Shuffle)
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);

    // Mengambil 5 kartu teratas untuk dimasukkan ke Hand
    Hand hand;
    for (int i = 0; i < 5; ++i) { 
        hand.cards.push_back(deck[i]);
    }

    return hand;
}