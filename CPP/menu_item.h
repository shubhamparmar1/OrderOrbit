#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>

class MenuItem {
public:
    MenuItem(const std::string& name, double price);
    const std::string& getName() const;
    double getPrice() const;
private:
    std::string name;
    double price;
};

#endif