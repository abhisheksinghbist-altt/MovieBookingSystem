#include <iostream>
using namespace std;

enum SeatType {
    SILVER,
    GOLD,
    PLATINUM
};

class Seat {
private:
    int seatNumber;
    SeatType type;

public:
    // Compile-time polymorphism: overloaded constructors
    Seat() {
        this->seatNumber = 0;
        this->type = SILVER;
    }

    Seat(int seatNumber, SeatType type) {
        this->seatNumber = seatNumber;
        this->type = type;
    }

    int getSeatNumber() {
        return this->seatNumber;
    }

    SeatType getType() {
        return this->type;
    }

    double getPrice() {
        const double SILVER_PRICE = 150;
        const double GOLD_PRICE = 250;
        const double PLATINUM_PRICE = 400;

        if (this->type == SILVER) {
            return SILVER_PRICE;
        }

        if (this->type == GOLD) {
            return GOLD_PRICE;
        }

        return PLATINUM_PRICE;
    }
};