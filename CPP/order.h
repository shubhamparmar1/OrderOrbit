#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include "menu_item.h"

enum class OrderStatus {
    PLACED,
    PREPARING,
    READY,
    DELIVERED
};

class Order {
public:
    Order(int tableNumber);
    void addItem(const MenuItem& item);
    const std::vector<MenuItem>& getItems() const;
    double getTotal() const;
    void applyDiscount(double percentage);
    void setSpecialRequest(const std::string& request);
    OrderStatus getStatus() const;
    void setStatus(OrderStatus status);
private:
    int tableNumber;
    std::vector<MenuItem> items;
    double discount;
    std::string specialRequest;
    OrderStatus status;
};

#endif