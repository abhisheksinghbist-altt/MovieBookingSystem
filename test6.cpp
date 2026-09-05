#include <iostream>
using namespace std;

class PriceCalculator
{
public:
    double calculateTotal(int silver, int gold, int platinum)
    {
        return silver * 150
             + gold * 250
             + platinum * 400;
    }
};

int main()
{
    PriceCalculator calculator;

    double total = calculator.calculateTotal(1, 1, 1);

    cout << "Total Amount: Rs. "
         << total << endl;

    return 0;
}