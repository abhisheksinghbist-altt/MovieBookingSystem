#include <iostream>
#include <string>
using namespace std;

class CardPayment : public Payment
{
private:
    string cardNumber;

public:
    CardPayment(string number)
    {
        this->cardNumber = number;
    }

    bool pay(double amount) override
    {
        cout << "Processing Card payment of Rs. " << amount << endl;
        cout << "Card ending with: "
             << cardNumber.substr(cardNumber.length() - 4) << endl;

        return true;
    }
};