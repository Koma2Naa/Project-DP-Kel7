#pragma once
#include <string>

class ShopItem {
public:
    ShopItem(std::string name, int price) : name(name), price(price) {}
    virtual ~ShopItem() = default;

    std::string getName() const { return name; }
    int getPrice() const { return price; }
    void setPrice(int p) { price = p; }

    virtual void onPurchase() = 0; 

protected:
    std::string name;
    int price;
};
