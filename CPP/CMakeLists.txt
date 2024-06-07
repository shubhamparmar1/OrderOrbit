cmake_minimum_required(VERSION 3.10)
project(restaurant_management_system)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_library(OrderOrbit SHARED
        table.cpp
        order.cpp
        order_manager.cpp
        menu_item.cpp)