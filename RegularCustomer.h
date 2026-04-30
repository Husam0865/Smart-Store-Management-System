#ifndef REGULARCUSTOMER_H
#define REGULARCUSTOMER_H
#include "Customer.h"

class RegularCustomer : public Customer
{
public:
    RegularCustomer(int id, string name, string phone);
    void displayInfo() const override;
    double calculateDiscount(double amount) const override;
};
#endif