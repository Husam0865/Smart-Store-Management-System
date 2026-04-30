#include "Payment.h"
#include <stdexcept>
using namespace std;

Payment::Payment(int id, double amount) : paymentId(id), amount(amount)
{
    if (amount < 0)
        throw invalid_argument("Payment amount cannot be negative.");
}

Payment::~Payment() {}

int Payment::getPaymentId() const { return paymentId; }
double Payment::getAmount() const { return amount; }
void Payment::setAmount(double a)
{
    if (a < 0)
        throw invalid_argument("Payment amount cannot be negative.");
    amount = a;
}