#include "OfficeSupply.h"
#include <iostream>
using namespace std;

// Constructor
OfficeSupply::OfficeSupply(int id, string name, double price, int quantity,
                           string category, string material)
    : Product(id, name, price, quantity), category(category), material(material) {}

// Setters
void OfficeSupply::setCategory(const string &c)
{
    category = c;
}

void OfficeSupply::setMaterial(const string &m)
{
    material = m;
}

// Getters
string OfficeSupply::getCategory() const
{
    return category;
}

string OfficeSupply::getMaterial() const
{
    return material;
}

// Override getType
string OfficeSupply::getType() const
{
    return "Office Supply";
}

// Override display
void OfficeSupply::display() const
{
    Product::display();
    cout << "Category: " << category << endl;
    cout << "Material: " << material << endl;
}