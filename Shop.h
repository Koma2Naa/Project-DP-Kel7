#pragma once
#include <vector>
#include <memory>
#include "ShopItem.h"

class Shop {
public:
    Shop();
    void rerollShop(const std::vector<std::string>& ownedItemNames); 
    std::vector<std::unique_ptr<ShopItem>> enterShop(int& playerMoney);
    
    // Allows expanding the shop size later (e.g. via an upgrade)
    void setMaxShopSize(int size) { maxShopSize = size; }

private:
    std::vector<std::unique_ptr<ShopItem>> availableItems;
    int maxShopSize = 3;
    
    // Generates the full pool of all possible items in the game
    std::vector<std::unique_ptr<ShopItem>> generateItemPool();
};
