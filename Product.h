#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;

class Product
{
protected:
    int id;
    string name;
    double price;
    int quantity;

public:
    Product(int id, string name, double price, int quantity);
    virtual ~Product();

    // Getters
    int getId() const;
    string getName() const;
    double getPrice() const;
    int getQuantity() const;

    // Setters
    void setPrice(double p);
    void setQuantity(int q);
};
#endif