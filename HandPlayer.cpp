#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include "HandPlayer.h"
using namespace std;

string getRankName(int rank) {
    if (rank == 11) return "Jack";
    if (rank == 12) return "Queen";
    if (rank == 13) return "King";
    if (rank == 14) return "Ace";
    return to_string(rank);
}

Hand HandPlayer::playHand(const Hand& generatedHand){
    Hand chosenHand;
    set<int> selectedIndices;
    cout << "Kartu di tanganmu:\n";
    for (size_t i = 0; i < generatedHand.cards.size(); i++) {
        cout << "[" << i << "] Rank: " << getRankName(generatedHand.cards[i].rank) 
              << " Suit: " << generatedHand.cards[i].suit << "\n";
    }

    cout << "Ketik indeks kartu yang ingin dimainkan (contoh: 0 1 4).\n";
    cout << "Tekan [ENTER] langsung untuk memainkan SEMUA kartu: ";
    
    string input;
    // // ws handles leading whitespace, then getline reads until newline
    // if (cin.peek() == '\n') cin.ignore(); 
    getline(cin, input);

    if (input.empty()) {
        cout << "Memainkan 5 kartu pertama...\n";
        for(int i=0; i < std::min(5, (int)generatedHand.cards.size()); i++) {
            chosenHand.cards.push_back(generatedHand.cards[i]);
        }
        return chosenHand;
    }

    stringstream ss(input);
    int index;
    while (ss >> index) {
        if (chosenHand.cards.size() >= 5) {
            cout << "Peringatan: Maksimal 5 kartu! Sisa pilihan diabaikan.\n";
            break;
        }
        
        if (index >= 0 && index < (int)generatedHand.cards.size()) {
            if (selectedIndices.find(index) == selectedIndices.end()) {
                chosenHand.cards.push_back(generatedHand.cards[index]);
                selectedIndices.insert(index);
            }
        } 
        
        else {
            cout << "Indeks " << index << " tidak valid dan akan dilewati!\n";
        }
    }
    
    return chosenHand;
}
