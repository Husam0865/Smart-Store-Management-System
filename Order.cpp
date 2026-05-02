#include "order.h"
#include <iostream>
#include <iomanip>
using namespace std;

Order::Order(int id, const string& date, Customer* cust)
    : orderId(id), orderDate(date), customer(cust),
    payment(nullptr), delivery(nullptr) {
}
Order::~Order() {}

void Order::addItem(Product* p, int qty) {
    items.emplace_back(p, qty);
}
void Order::setPayment(Payment* p) {
    payment = p;
}
void Order::setDelivery(Delivery* d) {
    delivery = d;
}
double Order::calculateSubtotal() const {
    double total = 0;
    for (const auto& item : items)
        total += item.calculateItemTotal();
    return total;
}
double Order::calculateFinalTotal()const {
    double subtotal = calculateSubtotal();
    double discount = customer->calculateDiscount(subtotal);
    double deliveryFee = (delivery != nullptr) ? delivery->getDeliveryFee() : 0.0;
    return subtotal - discount + deliveryFee;
}

void Order::printInvoice() const {
    cout << "====================================" << endl;
    cout << "         INVOICE #" << orderId << endl;
    cout << "Date: " << orderDate << endl;
    cout << "------------------------------------" << endl;

    cout << "Customer: ";
    customer->displayInfo();

    cout << "------------------------------------" << endl;
    cout << "Items:" << endl;
    for (const auto& item : items)
        item.display();

    double subtotal = calculateSubtotal();
    double discount = customer->calculateDiscount(subtotal);
    double deliveryFee = (delivery != nullptr) ? delivery->getDeliveryFee() : 0.0;
    double finalTotal = subtotal - discount + deliveryFee;

    cout << "------------------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "subTotal:        " << subtotal << endl;
    cout << "discount:       -" << discount << endl;
    cout << "Delicery Fee:   +" << deliveryFee << endl;
    cout << "FINAL TOTAL:     " << finalTotal << endl;
    cout << "------------------------------------" << endl;

    cout << "Payment: ";
    if (payment) {
        payment->setAmount(finalTotal);
        payment->pay();
    }
    else
        cout << "No payment set" << endl;
    if (delivery) {
        cout << "Delivery Info: ";
        delivery->displayDeliveryInfo();
    }
    else {
        cout << "Order Type:Pickupc(no delivery fee)" << endl;
    }

    cout << "=====================================" << endl;
}