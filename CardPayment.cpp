#include "CardPayment.h"
#include <iostream>
#include <stdexcept>
using namespace std;

CardPayment::CardPayment(int id, double amount, string cardNumber)
    : Payment(id, amount), cardNumber(cardNumber)
{
    validateCard();
}

void CardPayment::setCardNumber(const string &number)
{
    cardNumber = number;
    validateCard();
}

string CardPayment::getCardNumber() const { return cardNumber; }

void CardPayment::validateCard() const
{
    if (cardNumber.length() != 16)
        throw invalid_argument("Card number must be exactly 16 digits.");
    for (char c : cardNumber)
        if (!isdigit(c))
            throw invalid_argument("Card number must contain digits only.");
}

void CardPayment::pay()
{
    validateCard();
    cout << "Card payment of $" << amount << " processed. Card: ****"
         << cardNumber.substr(12) << "\n";
}

string CardPayment::getPaymentType() const { return "Card"; }