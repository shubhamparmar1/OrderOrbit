#include "menu_item.h"

MenuItem::MenuItem(const std::string& name, double price) : name(name), price(price) {}

const std::string& MenuItem::getName() const {
    return name;
}

double MenuItem::getPrice() const {
    return price;
}