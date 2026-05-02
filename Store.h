#pragma once
#include<vector>
#include<string>
#include"Product.h"
#include"Customer.h"

using namespace std;
class Order;
class Store{
private:
    string name;
    vector<Product*> products;
    vector<Customer*> customers;
    vector<Order*> orders;

public:
    Store(const string& name);

    void addProduct(Product* P);
    void addCustomer(Customer* c);
    void addOrder(Order* o);
    void displayStoreSummary() const;
};