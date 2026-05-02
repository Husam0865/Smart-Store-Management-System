#pragma once
#include <vector>
#include <string>
#include "orderItem.h"
#include "Customer.h"
#include "Payment.h"
#include "Delivery.h"
using namespace std;

class Order{
private:
    int orderId;
    string orderDate;
    Customer* customer;
    Payment* payment;
    Delivery* delivery;
    vector<OrderItem> items;
public:
    Order(int id,const string&date, Customer* cust);
    ~Order();

    void addItem(Product*cp, int qty);
    void setPayment(Payment* p);
    void setDelivery(Delivery* d);

    double calculateSubtotal() const;
    double calculateFinalTotal() const;
    void printInvoice() const;
};