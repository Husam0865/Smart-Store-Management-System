#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    int id;
    string name;
    double price;
    int quantity;
    static int productCount;

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

    // Static method to get product count
    static int getProductCount();

    // Virtual method to display product details
    virtual void display() const;

    // Update quantity after purchases
    void purchase(int amount);

    // Method to add products
    void addQuantity(int qty);
};
#endif