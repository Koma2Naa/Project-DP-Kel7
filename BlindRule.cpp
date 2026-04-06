#include <iostream>
#include "BlindRule.h"
using namespace std;
bool BlindRule::checkBlind(int score){
    cout << "Checking blind requirement...\n";
    
    if (score >= 5){
    cout << "Result: WIN\n";
    return true;
    }

    cout << "Result: LOSE\n";
    return false;
}