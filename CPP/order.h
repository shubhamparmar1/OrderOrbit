#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "menu_item.h"

class Order {
public:
    Order(int tableNumber);
    void addItem(const MenuItem& item);
    const std::vector<MenuItem>& getItems() const;
private:
    int tableNumber;
    std::vector<MenuItem> items;
};

#endif