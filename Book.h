#ifndef BOOK_H
#define BOOK_H

#include "Product.h"

class Book : public Product {
private:
    string author;
    int pages;
};
#endif