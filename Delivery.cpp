#include "Delivery.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Delivery::Delivery(int id, string address, double fee, string driverName)
    : deliveryId(id), address(address), deliveryFee(fee),
      driverName(driverName), status("Pending")
{
    if (fee < 0)
        throw invalid_argument("Delivery fee cannot be negative.");
}

void Delivery::setStatus(const string &s) { status = s; }
void Delivery::setDriverName(const string &d) { driverName = d; }

int Delivery::getDeliveryId() const { return deliveryId; }
string Delivery::getAddress() const { return address; }
string Delivery::getStatus() const { return status; }
double Delivery::getDeliveryFee() const { return deliveryFee; }
string Delivery::getDriverName() const { return driverName; }

void Delivery::displayDeliveryInfo() const
{
    cout << "Delivery ID  : " << deliveryId << "\n";
    cout << "Address      : " << address << "\n";
    cout << "Status       : " << status << "\n";
    cout << "Fee          : $" << deliveryFee << "\n";
    cout << "Driver       : " << driverName << "\n";
}