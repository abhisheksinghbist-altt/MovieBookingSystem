#include <iostream>
#include <string>
using namespace std;

class Payment
{
public:
    virtual bool pay(double amount) = 0;

    virtual ~Payment() {}
};

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
        cout << "UPI payment of Rs. "
             << amount << " successful." << endl;

        return true;
    }
};

class CardPayment : public Payment
{
public:
    bool pay(double amount) override
    {
        cout << "Card payment of Rs. "
             << amount << " successful." << endl;

        return true;
    }
};

class CashPayment : public Payment
{
public:
    bool pay(double amount) override
    {
        cout << "Cash payment of Rs. "
             << amount << " received." << endl;

        return true;
    }
};

int main()
{
    double amount = 550;

    Payment* payment;

    payment = new UpiPayment("abhishek@upi");
    payment->pay(amount);
    delete payment;

    payment = new CardPayment();
    payment->pay(amount);
    delete payment;

    payment = new CashPayment();
    payment->pay(amount);
    delete payment;

    return 0;
}