#ifndef BOOK_H
#define BOOK_H

#include "Product.h"

class Book : public Product
{
private:
    string author;
    int pages;

public:
    Book(int id, string name, double price, int quantity,
         string author, int pages);
    // Setters
    void setAuthor(const string &a);
    void setPages(int p);
    // Getters
    string getAuthor() const;
    int getPages() const;
    // Override virtual functions
    string getType() const override;
    void display() const override;
};
#endif