#include "order.h"

Order::Order(int tableNumber) : tableNumber(tableNumber), discount(0.0), status(OrderStatus::PLACED) {}

void Order::addItem(const MenuItem& item) {
    items.push_back(item);
}

const std::vector<MenuItem>& Order::getItems() const {
    return items;
}

double Order::getTotal() const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.getPrice();
    }
    return total * (1.0 - discount);
}

void Order::applyDiscount(double percentage) {
    discount = percentage;
}

void Order::setSpecialRequest(const std::string& request) {
    specialRequest = request;
}

OrderStatus Order::getStatus() const {
    return status;
}

void Order::setStatus(OrderStatus status) {
    this->status = status;
}