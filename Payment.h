#ifndef PAYMENT_H
#define PAYMENT_H
#include <string>
using namespace std;

class Payment
{
protected:
    int paymentId;
    double amount;

public:
    Payment(int id, double amount);
    virtual ~Payment();
    int getPaymentId() const;
    double getAmount() const;
    void setAmount(double amount);
    virtual void pay() = 0;
    virtual string getPaymentType() const = 0;
};
#endif