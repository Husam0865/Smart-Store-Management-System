#ifndef OFFICESUPPLY_H
#define OFFICESUPPLY_H

#include "Product.h"

class OfficeSupply : public Product
{
private:
    string category;
    string material;

public:
    OfficeSupply(int id, string name, double price, int quantity,
                 string category, string material);
    // Setters
    void setCategory(const string &c);
    void setMaterial(const string &m);
    // Getters
    string getCategory() const;
    string getMaterial() const;
    // Override virtual functions
    string getType() const override;
    void display() const override;
};
#endif