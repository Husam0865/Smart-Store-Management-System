#include "ElectronicDevice.h"
#include <iostream>
using namespace std;

// Constructor
ElectronicDevice::ElectronicDevice(int id, string name, double price, int quantity,
                                   string brand, int warrantyMonths)
    : Product(id, name, price, quantity), brand(brand), warranty(warrantyMonths) {}

// Setters
void ElectronicDevice::setBrand(const string &b) {
    brand = b;
}

void ElectronicDevice::setWarrantyMonths(int w) {
    warranty = w;
}

// Getters
string ElectronicDevice::getBrand() const {
    return brand;
}

int ElectronicDevice::getWarrantyMonths() const {
    return warranty;
}

// Override getType
string ElectronicDevice::getType() const {
    return "Electronic Device";
}

// Override display
void ElectronicDevice::display() const {
    Product::display();
    cout << "Brand   : " << brand << endl;
    cout << "Warranty: " << warranty << " months" << endl;
}