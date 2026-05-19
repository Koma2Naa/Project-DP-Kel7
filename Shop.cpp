#include "Shop.h"
#include <iostream>
#include <limits>

using namespace std;

Shop::Shop() {
}

void Shop::rerollShop() {
    availableItems.clear();
    // In the future, randomly populate availableItems with new ShopItems here.
}

void Shop::enterShop(int& playerMoney) {
    cout << "\n=== Welcome to the Shop! ===\n";
    cout << "You have $" << playerMoney << "\n";
    
    if (availableItems.empty()) {
        cout << "The shop is completely empty right now.\n";
    } else {
        // Future logic: Loop through availableItems, display them, 
        // and ask the user for input to buy them.
    }
    
    cout << "Press [ENTER] to leave the shop...";
    // Clear any potential characters left in buffer and wait for enter
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Leaving shop...\n";
}
