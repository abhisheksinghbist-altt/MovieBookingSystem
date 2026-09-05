#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Seat {
private:
    int seatNumber;

public:
    Seat(int seatNumber) {
        this->seatNumber = seatNumber;
    }

    int getSeatNumber() {
        return this->seatNumber;
    }
};

enum SeatStatus {
    AVAILABLE,
    BOOKED
};

class ShowSeat {
private:
    Seat* seat;
    SeatStatus status;

public:
    ShowSeat(Seat* seat) {
        this->seat = seat;
        this->status = AVAILABLE;
    }

    bool isAvailable() {
        return this->status == AVAILABLE;
    }

    bool bookSeat() {

        if (this->status == BOOKED)
            return false;

        this->status = BOOKED;
        return true;
    }

    void cancelSeat() {
        this->status = AVAILABLE;
    }

    Seat* getSeat() {
        return this->seat;
    }
};

int main() {

    Seat seat1(1);

    ShowSeat showSeat(&seat1);

    cout << "Initial status: ";

    if (showSeat.isAvailable())
        cout << "AVAILABLE";
    else
        cout << "BOOKED";

    cout << endl;

    cout << "Booking seat..." << endl;

    if (showSeat.bookSeat())
        cout << "Seat booked successfully." << endl;
    else
        cout << "Seat already booked." << endl;

    cout << "Trying to book the same seat again..." << endl;

    if (showSeat.bookSeat())
        cout << "Seat booked successfully." << endl;
    else
        cout << "Seat already booked. Booking rejected." << endl;

    cout << "Cancelling booking..." << endl;

    showSeat.cancelSeat();

    if (showSeat.isAvailable())
        cout << "Seat is AVAILABLE again." << endl;

    return 0;
}