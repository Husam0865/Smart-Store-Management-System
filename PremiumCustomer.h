#ifndef PREMIUMCUSTOMER_H
#define PREMIUMCUSTOMER_H
#include "Customer.h"

class PremiumCustomer : public Customer
{
private:
    double discountRate;

public:
    PremiumCustomer(int id, string name, string phone, double discountRate);
    void setDiscountRate(double rate);
    double getDiscountRate() const;
    void displayInfo() const override;
    double calculateDiscount(double amount) const override;
};
#endif