#include "Product.h"
#include <stdexcept>
using namespace std;

int Product::productCount = 0;

// Constructor
Product::Product(int id, string name, double price, int quantity)
    : id(id), name(name), price(price), quantity(quantity)
{
    if (price < 0)
        throw invalid_argument("Price cannot be negative.");
    if (quantity < 0)
        throw invalid_argument("Quantity cannot be negative.");
    productCount++;
}

// Destructor
Product::~Product() { productCount--; }

// Getters
int Product::getId() const { return id; }
string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }

// Setters
void Product::setPrice(double p) { price = p; }
void Product::setQuantity(int q) { quantity = q; }

// Static
int Product::getProductCount() { return productCount; }

// Quantity methods
void Product::purchase(int amount)
{
    if (amount > quantity)
        throw runtime_error("Not enough stock for: " + name);
    quantity -= amount;
}

void Product::addQuantity(int qty) { quantity += qty; }

// Display
void Product::display() const
{
    cout << "-----------------------------\n";
    cout << "ID       : " << id << "\n";
    cout << "Name     : " << name << "\n";
    cout << "Price    : $" << price << "\n";
    cout << "Quantity : " << quantity << "\n";
}

// File I/O
void Product::saveToFile(ofstream &out) const
{
    out << id << "\n"
        << name << "\n"
        << price << "\n"
        << quantity << "\n";
}

// Operators
Product &Product::operator+(int qty)
{
    if (qty < 0)
        throw invalid_argument("Cannot add negative quantity.");
    quantity += qty;
    return *this;
}

bool Product::operator==(const Product &o) const { return id == o.id; }

ostream &operator<<(ostream &os, const Product &p)
{
    os << "[" << p.getType() << "] "
       << "ID:" << p.id
       << " | " << p.name
       << " | $" << p.price
       << " | Qty:" << p.quantity;
    return os;
}

// Friend function
bool comparePrice(const Product &a, const Product &b)
{
    if (a.price > b.price)
    {
        cout << a.name << " ($" << a.price << ") is more expensive than "
             << b.name << " ($" << b.price << ")\n";
        return true;
    }
    else
    {
        cout << b.name << " ($" << b.price << ") is more expensive than "
             << a.name << " ($" << a.price << ")\n";
        return false;
    }
}