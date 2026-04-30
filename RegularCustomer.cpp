#include "RegularCustomer.h"
#include <iostream>
using namespace std;

RegularCustomer::RegularCustomer(int id, string name, string phone)
    : Customer(id, name, phone) {}

void RegularCustomer::displayInfo() const
{
    cout << "Regular Customer\n";
    cout << "ID   : " << customerId << "\n";
    cout << "Name : " << name << "\n";
    cout << "Phone: " << phone << "\n";
}

double RegularCustomer::calculateDiscount(double amount) const
{
    return 0.0;
}