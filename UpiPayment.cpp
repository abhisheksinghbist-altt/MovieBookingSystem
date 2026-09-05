#include <iostream>
#include <string>
using namespace std;

class UpiPayment : public Payment
{
private:
    string upiId;

public:
    UpiPayment(string id)
    {
        this->upiId = id;
    }

    bool pay(double amount) override
    {
        cout << "Processing UPI payment of Rs. " << amount << endl;
        cout << "UPI ID: " << upiId << endl;

        return true;
    }
};