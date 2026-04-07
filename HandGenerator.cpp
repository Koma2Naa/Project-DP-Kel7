#include <iostream>
#include <cstdlib>
#include <ctime>
#include "HandGenerator.h"
using namespace std;

Hand HandGenerator::generateHand(){
    std::cout << "Generating cards for player...\n";
    
    Hand hand;
    srand(time(0));
    hand.value = rand() % 13 + 1;
    return hand;
}