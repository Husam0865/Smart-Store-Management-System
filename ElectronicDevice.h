#ifndef ELECTRONICDEVICE_H
#define ELECTRONICDEVICE_H

#include "Product.h"

class ElectronicDevice : public Product {
private:
    string brand;
    int warranty;
};
#endif