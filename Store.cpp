#include"Store.h"
#include"Order.h"
#include<iostream>
using namespace std;

Store::Store(const string& n) : name(n) {}
void Store::addProduct(Product* p) {
    products.push_back(p);
}
void Store::addCustomer(Customer* c) {
    customers.push_back(c);
}
void Store::addOrder(Order* o) {
    orders.push_back(o);
}
void Store::displayStoreSummary() const {
    cout << "========================================" << endl;
    cout << "  STORE SUMMARY: " << name << endl;
    cout << "========================================" << endl;

    cout << "\n--- Products (" << products.size() << ") ---" << endl;
    for (auto p : products)
        p->display();

    cout << "\n--- Customers (" << customers.size() << ") ---" << endl;
    for (auto c : customers)
        c->displayInfo();

    cout << "\n--- Orders (" << orders.size() << ") ---" << endl;
    for (auto o : orders)
        o->printInvoice();

    cout << "\nTotal Products in system: " << Product::getProductCount() << endl;
    cout << "========================================" << endl;
}
