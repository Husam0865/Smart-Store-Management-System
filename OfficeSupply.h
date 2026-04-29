#ifndef OFFICESUPPLY_H
#define OFFICESUPPLY_H

#include "Product.h"

class OfficeSupply : public Product {
private:
    string category;
    string material;
};
#endif