#include <iostream>
#include <vector>
using namespace std;

class PriceCalculator
{
private:
    static const double SILVER_PRICE;
    static const double GOLD_PRICE;
    static const double PLATINUM_PRICE;

public:
    double calculateTotal(vector<ShowSeat*> seats)
    {
        double total = 0;

        for (ShowSeat* showSeat : seats)
        {
            Seat* seat = showSeat->getSeat();

            if (seat->getType() == SILVER)
            {
                total += SILVER_PRICE;
            }
            else if (seat->getType() == GOLD)
            {
                total += GOLD_PRICE;
            }
            else if (seat->getType() == PLATINUM)
            {
                total += PLATINUM_PRICE;
            }
        }

        return total;
    }
};

const double PriceCalculator::SILVER_PRICE = 150;
const double PriceCalculator::GOLD_PRICE = 250;
const double PriceCalculator::PLATINUM_PRICE = 400;