#include <iostream>
#include "HandPlayer.h"
using namespace std;

Hand HandPlayer::playHand(const Hand& generatedHand){
    Hand chosenHand;
    cout << "Kartu di tanganmu:\n";
    for (size_t i = 0; i < generatedHand.cards.size(); i++) {
        cout << "[" << i << "] Rank: " << generatedHand.cards[i].rank 
              << " Suit: " << generatedHand.cards[i].suit << "\n";
    }

    cout << "Pilih indeks kartu yang ingin dimainkan (pisahkan dengan spasi, ketik -1 jika selesai memilih):\n";
    int index;
    while (cin >> index && index != -1) {
        if (index >= 0 && index < generatedHand.cards.size()) {
            chosenHand.cards.push_back(generatedHand.cards[index]);
        } else {
            cout << "Indeks tidak valid!\n";
        }
    }
    
    cout << "Memainkan " << chosenHand.cards.size() << " kartu...\n";
    return chosenHand;
}