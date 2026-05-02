#pragma once
#include "Product.h"
class OrderItem{
private:
    Product*product;
    int quantity;
    double unitPriceAtPurchase;
public:
    OrderItem(Product* p, int qty);
    double calculateItemTotal() const;
    void display() const;
    Product* getProduct() const;
        int getQuantity() const;
        double getUnitPrice() const;        
};