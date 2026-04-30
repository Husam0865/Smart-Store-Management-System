#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;

class Customer
{
protected:
    int customerId;
    string name;
    string phone;

public:
    Customer(int id, string name, string phone);
    virtual ~Customer();
    int getCustomerId() const;
    string getName() const;
    string getPhone() const;
    virtual void displayInfo() const = 0;
    virtual double calculateDiscount(double amount) const = 0;
};
#endif