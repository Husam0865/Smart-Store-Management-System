#include "OrderItem.h"
#include <iostream>
using namespace std;

OrderItem::OrderItem(Product* p, int qty) {
    product = p;
    quantity = qty;
    unitPriceAtPurchase = p->getPrice();
}

double OrderItem::calculateItemTotal() const {
    return unitPriceAtPurchase * quantity;
}

void OrderItem::display() const {
    cout << "Product: " << product->getName()
        << ", Quantity: " << quantity
        << ", Unit Price: " << unitPriceAtPurchase
        << ", Total: " << calculateItemTotal() << endl;
}

Product* OrderItem::getProduct() const {
    return product;
}

int OrderItem::getQuantity() const {
    return quantity;
}

double OrderItem::getUnitPrice() const {
    return unitPriceAtPurchase;
}