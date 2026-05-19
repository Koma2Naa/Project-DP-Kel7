#pragma once
#include <vector>
#include <memory>
#include "ShopItem.h"

class Shop {
public:
    Shop();
    void rerollShop(); 
    void enterShop(int& playerMoney);

private:
    std::vector<std::unique_ptr<ShopItem>> availableItems;
};
