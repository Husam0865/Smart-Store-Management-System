#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(int id, string name, string phone)
    : customerId(id), name(name), phone(phone) {}

Customer::~Customer() {}

int Customer::getCustomerId() const { return customerId; }
string Customer::getName() const { return name; }
string Customer::getPhone() const { return phone; }