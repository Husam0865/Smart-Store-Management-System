#include "CashPayment.h"
#include <iostream>
using namespace std;

CashPayment::CashPayment(int id, double amount) : Payment(id, amount) {}

void CashPayment::pay()
{
    cout << "Cash payment of $" << amount << " processed successfully.\n";
}

string CashPayment::getPaymentType() const { return "Cash"; }