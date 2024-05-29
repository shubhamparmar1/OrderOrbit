#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <vector>
#include "order.h"

class OrderManager {
public:
    void placeOrder(const Order& order);
    void updateOrderStatus(int orderId, OrderStatus status);
    const std::vector<Order>& getOrderHistory() const;
private:
    std::vector<Order> orders;
};

#endif