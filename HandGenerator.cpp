#include <iostream>
#include <cstdlib>
#include <ctime>
#include "HandGenerator.h"
using namespace std;

Hand HandGenerator::generateHand(){
    std::cout << "Generating cards for player...\n";
    
    Hand hand;
    // srand(time(0));
    // hand.value = rand() % 13 + 1;
    for (int i = 0; i < 8; i++){
        Card card;
        card.rank = rand() % 13 + 1; // Rank between 1 and 13
        char suits[] = {'H', 'D', 'C', 'S'}; // Hearts, Diamonds, Clubs, Spades
        card.suit = suits[rand() % 4 + 1]; // Randomly select a suit
        hand.cards.push_back(card);
    }
    return hand;
}