#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

    // pure virtual function to get product type
    virtual string getType() const = 0;

    // friend function to compare products by price
    friend bool comparePrice(const Product &a, const Product &b);

    // Operators
    bool operator==(const Product &o) const;
    friend ostream &operator<<(ostream &os, const Product &p);

    // File I/O
    void saveToFile(ofstream &out) const;
    static vector<Product> loadFromFile(ifstream &in);
};
#endif