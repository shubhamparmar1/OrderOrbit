#include "order_manager.h"

void OrderManager::placeOrder(const Order& order) {
    orders.push_back(order);
}

void OrderManager::updateOrderStatus(int orderId, OrderStatus status) {
    if (orderId >= 0 && orderId < orders.size()) {
        orders[orderId].setStatus(status);
    }
}

const std::vector<Order>& OrderManager::getOrderHistory() const {
    return orders;
}