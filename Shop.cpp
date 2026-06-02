#include "Shop.h"
#include "JokerFactory.h"
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <random>
#include <algorithm>

using namespace std;

Shop::Shop() {
}

void Shop::rerollShop(const std::vector<std::string>& ownedItemNames, int& freeJokersCount) {
    availableItems.clear();
    
    auto fullPool = JokerFactory::generateFullJokerPool();
    std::vector<std::unique_ptr<ShopItem>> filteredPool;

    // Filter out items the player already owns
    for (auto& item : fullPool) {
        bool owned = false;
        for (const auto& name : ownedItemNames) {
            if (item->getName() == name) {
                owned = true;
                break;
            }
        }
        if (!owned) {
            filteredPool.push_back(std::move(item));
        }
    }

    // Shuffle the filtered pool to randomize shop offerings
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(filteredPool.begin(), filteredPool.end(), g);

    // Pick up to maxShopSize items
    int itemsToPick = std::min(maxShopSize, static_cast<int>(filteredPool.size()));
    for (int i = 0; i < itemsToPick; ++i) {
        // Apply Free Joker Tag discount
        if (freeJokersCount > 0) {
            filteredPool[i]->setPrice(0);
            freeJokersCount--;
            cout << "[SHOP] " << filteredPool[i]->getName() << " is FREE due to a Tag!\n";
        }
        availableItems.push_back(std::move(filteredPool[i]));
    }
}

std::vector<std::unique_ptr<ShopItem>> Shop::enterShop(int& playerMoney) {
    std::vector<std::unique_ptr<ShopItem>> purchasedItems;
    bool inShop = true;

    while (inShop) {
        cout << "\n=== Welcome to the Shop! ===\n";
        cout << "You have $" << playerMoney << "\n";
        
        if (availableItems.empty()) {
            cout << "The shop is completely empty right now.\n";
            inShop = false;
        } else {
            for (size_t i = 0; i < availableItems.size(); ++i) {
                cout << "[" << i << "] " << availableItems[i]->getName() 
                     << " ($" << availableItems[i]->getPrice() << ")\n";
            }
            
            cout << "Enter the index of the item to buy, or press [ENTER] to leave: ";
            string input;
            getline(cin, input);

            if (input.empty()) {
                inShop = false;
                continue;
            }

            stringstream ss(input);
            int index;
            if (ss >> index && index >= 0 && index < (int)availableItems.size()) {
                int price = availableItems[index]->getPrice();
                if (playerMoney >= price) {
                    playerMoney -= price;
                    availableItems[index]->onPurchase();
                    purchasedItems.push_back(std::move(availableItems[index]));
                    availableItems.erase(availableItems.begin() + index);
                    cout << "Purchase successful! You have $" << playerMoney << " remaining.\n";
                } else {
                    cout << "You don't have enough money! You need $" << price << ".\n";
                }
            } else {
                cout << "Invalid index!\n";
            }
        }
    }
    
    cout << "Leaving shop...\n";
    return purchasedItems;
}
