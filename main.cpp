#include<iostream>
#include<fstream>
#include<stdexcept>
#include"Store.h"
#include"Book.h"
#include"ElectronicDevice.h"
#include"OfficeSupply.h"
#include"RegularCustomer.h"
#include"PremiumCustomer.h"
#include"CashPayment.h"
#include"CardPayment.h"
#include"Delivery.h"
#include"Order.h"
using namespace std;

int main() {
    Book* b1 = new Book(1, "A tale of two cities",100.12,3,"Charles Dekiens",250);
    ElectronicDevice* e1 = new ElectronicDevice(2,"Iphone17",1200,2,"Apple",12);
    ElectronicDevice* e2 = new ElectronicDevice(3,"Headphones",200.34,1,"Hwawie",6);
    OfficeSupply* o1 = new OfficeSupply(4,"Desk",500,10,"Office Tools","Wood");

    Product* arr[] = { b1, e1, e2, o1 };
    int size = 4;
    Product* mostExpensive = findMaxPrice(arr, size);
    cout << "Most expensive:" << mostExpensive->getName() << endl;

    vector<Product*> allProduct = {b1, e1, e2, o1};

    ofstream outFile("product.txt");
    for(auto p : allProduct)
        p->saveToFile(outFile);
    outFile.close();

    cout << "===Operator Overloading===" << endl;
    cout << *b1 << endl;
    *e1 + 3;
    cout << "Laptop qty after +3: " << e1->getQuantity() << endl;
    bool result = b1->operator==(*e1);
    cout << "b1==e1 ?" << (result ? "yes" : "no") << endl;

    cout << "===Friend Function===" << endl;
    comparePrice(*b1, *e1);

    cout << "===Template: findMaxPrice===" << endl;
    cout << "Most expensive:" << mostExpensive->getName() << endl;

    cout << "Total products created:" << Product::getProductCount() << endl;

    cout << "===Polymorphism===" << endl;
    for(Product* p : allProduct)
        p->display();

    RegularCustomer* cust1 = new RegularCustomer(1,"ghazi","01109809717");
    PremiumCustomer* cust2 = new PremiumCustomer(2,"Awab","1234567890",0.10);

    CashPayment* cash = new CashPayment(1,20);
    CardPayment* card = new CardPayment(2,100,"1234567890098765");

    Delivery* del = new Delivery(1,"92 mohammedfarid st,cairo",70.0,"ahmed");
    del->setStatus("shipped");

    Store myStore("Smart Store");
    for(auto p : allProduct) myStore.addProduct(p);
    myStore.addCustomer(cust1);
    myStore.addCustomer(cust2);

    cout << "\n===Order1: Regular Customer+Cash+Delivery===" << endl;
    Order* order1 = new Order(1,"2026-04-30",cust1);
    try {
        order1->addItem(b1,2);
        order1->addItem(e2,1);
    }
    catch(exception& ex) {
        cout << "Order1 item error: " << ex.what() << endl;
    }
    order1->setPayment(cash);
    order1->setDelivery(del);
    order1->printInvoice();
    myStore.addOrder(order1);

    cout << "\n===Order2: Premium Customer+Card+Pickup===" << endl;
    Order* order2 = new Order(2,"2026-04-30",cust2);
    try {
        order2->addItem(e1,1);
        order2->addItem(o1,3);
    }
    catch(exception& ex) {
        cout << "Order2 item error: " << ex.what() << endl;
    }
    order2->setPayment(card);
    order2->printInvoice();
    myStore.addOrder(order2);

    cout << "\n===Exception: Invalid Quantity===" << endl;
    try {
        Order* badOrder = new Order(2,"2026-04-30",cust1);
        badOrder->addItem(b1,-1);
        delete badOrder;
    }
    catch(exception& ex) {
        cout << "Caught: " << ex.what() << endl;
    }

    cout << "\n===Exception: Insufficient Stock===" << endl;
    try {
        Order* badOrder2 = new Order(2,"2026-04-30",cust2);
        badOrder2->addItem(e1,10000000);
        delete badOrder2;
    }
    catch(exception& ex) {
        cout << "Caught: " << ex.what() << endl;
    }

    delete b1; delete e1; delete e2; delete o1;
    delete cust1; delete cust2;
    delete cash; delete card;
    delete del;
    delete order1; delete order2;

    return 0;
}