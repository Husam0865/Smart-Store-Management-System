#include "Book.h"
#include <iostream>
using namespace std;

// Constructor
Book::Book(int id, string name, double price, int quantity,
           string author, int pages)
    : Product(id, name, price, quantity), author(author), pages(pages) {}

// Setters
void Book::setAuthor(const string &a)
{
    author = a;
}

void Book::setPages(int p)
{
    pages = p;
}

// Getters
string Book::getAuthor() const
{
    return author;
}

int Book::getPages() const
{
    return pages;
}

// Override getType
string Book::getType() const
{
    return "Book";
}

// Override display
void Book::display() const
{
    Product::display();
    cout << "Author : " << author << endl;
    cout << "Pages  : " << pages << endl;
}