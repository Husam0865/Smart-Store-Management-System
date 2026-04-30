#ifndef CARDPAYMENT_H
#define CARDPAYMENT_H
#include "Payment.h"

class CardPayment : public Payment
{
private:
    string cardNumber;

public:
    CardPayment(int id, double amount, string cardNumber);
    void setCardNumber(const string &number);
    string getCardNumber() const;
    void validateCard() const;
    void pay() override;
    string getPaymentType() const override;
};
#endif