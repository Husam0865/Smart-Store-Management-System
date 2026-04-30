#include "PremiumCustomer.h"
#include <iostream>
#include <stdexcept>
using namespace std;

PremiumCustomer::PremiumCustomer(int id, string name, string phone, double discountRate)
    : Customer(id, name, phone), discountRate(discountRate)
{
    if (discountRate < 0 || discountRate > 1)
        throw invalid_argument("Discount rate must be between 0 and 1.");
}

void PremiumCustomer::setDiscountRate(double rate)
{
    if (rate < 0 || rate > 1)
        throw invalid_argument("Discount rate must be between 0 and 1.");
    discountRate = rate;
}

double PremiumCustomer::getDiscountRate() const { return discountRate; }

void PremiumCustomer::displayInfo() const
{
    cout << "Premium Customer\n";
    cout << "ID            : " << customerId << "\n";
    cout << "Name          : " << name << "\n";
    cout << "Phone         : " << phone << "\n";
    cout << "Discount Rate : " << discountRate * 100 << "%\n";
}

double PremiumCustomer::calculateDiscount(double amount) const
{
    return amount * discountRate;
}