#ifndef ELECTRONICDEVICE_H
#define ELECTRONICDEVICE_H

#include "Product.h"

class ElectronicDevice : public Product
{
private:
    string brand;
    int warranty;

public:
    ElectronicDevice(int id, string name, double price, int quantity,
                     string brand, int warrantyMonths);
    // Setters
    void setBrand(const string &b);
    void setWarrantyMonths(int w);
    // Getters
    string getBrand() const;
    int getWarrantyMonths() const;
    // Override virtual functions
    string getType() const override;
    void display() const override;
};
#endif