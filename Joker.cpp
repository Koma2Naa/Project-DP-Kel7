#include "Joker.h"
#include <iostream>

Joker::Joker(std::string name, int price) : ShopItem(name, price) {}

void Joker::onPurchase() {
    std::cout << "Purchased Joker: " << name << " for $" << price << "\n";
    // Usually, the shop/manager would handle adding this to the active collection.
}
