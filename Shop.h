#pragma once
#include <vector>
#include <memory>
#include "ShopItem.h"

class Shop {
public:
    Shop();
    void rerollShop(const std::vector<std::string>& ownedItemNames, int& freeJokersCount); 
    std::vector<std::unique_ptr<ShopItem>> enterShop(int& playerMoney);
    
    // Allows expanding the shop size later (e.g. via an upgrade)
    void setMaxShopSize(int size) { maxShopSize = size; }

private:
    std::vector<std::unique_ptr<ShopItem>> availableItems;
    int maxShopSize = 3;
};
