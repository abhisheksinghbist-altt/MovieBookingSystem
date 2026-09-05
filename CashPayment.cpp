#include <iostream>
using namespace std;

class CashPayment : public Payment
{
public:
    CashPayment()
    {
    }

    bool pay(double amount) override
    {
        cout << "Cash payment received: Rs. "
             << amount << endl;

        return true;
    }
};