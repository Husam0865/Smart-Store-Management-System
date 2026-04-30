#ifndef DELIVERY_H
#define DELIVERY_H
#include <string>
using namespace std;

class Delivery
{
private:
    int deliveryId;
    string address;
    string status;
    double deliveryFee;
    string driverName;

public:
    Delivery(int id, string address, double fee, string driverName);
    void setStatus(const string &status);
    void setDriverName(const string &driver);
    int getDeliveryId() const;
    string getAddress() const;
    string getStatus() const;
    double getDeliveryFee() const;
    string getDriverName() const;
    void displayDeliveryInfo() const;
};
#endif