cmake_minimum_required(VERSION 3.29)
project(restaurant_management_system)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_library(OrderOrbit SHARED
        CPP/table.cpp
        CPP/order.cpp
        CPP/order_manager.cpp
        CPP/menu_item.cpp)