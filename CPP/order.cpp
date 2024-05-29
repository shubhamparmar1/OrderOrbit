#include "order.h"

Order::Order(int tableNumber) : tableNumber(tableNumber) {}

void Order::addItem(const MenuItem& item) {
    items.push_back(item);
}

const std::vector<MenuItem>& Order::getItems() const {
    return items;
}