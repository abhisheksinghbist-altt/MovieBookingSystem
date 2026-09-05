#include <iostream>
#include <vector>
using namespace std;

class Show;
class ShowSeat;

enum BookingStatus {
    PENDING,
    CONFIRMED,
    CANCELLED
};

class Booking {
private:
    static int nextBookingId;

    int bookingId;
    Show* show;
    vector<ShowSeat*> seats;
    double totalAmount;
    BookingStatus status;

public:

    Booking(Show* show,
            vector<ShowSeat*> seats,
            double totalAmount) {

        this->bookingId = nextBookingId++;
        this->show = show;
        this->seats = seats;
        this->totalAmount = totalAmount;
        this->status = PENDING;
    }

    // Overloaded constructor
    Booking(Show* show,
            vector<ShowSeat*> seats) {

        this->bookingId = nextBookingId++;
        this->show = show;
        this->seats = seats;
        this->totalAmount = 0;
        this->status = PENDING;
    }

    int getBookingId() {
        return this->bookingId;
    }

    Show* getShow() {
        return this->show;
    }

    vector<ShowSeat*> getSeats() {
        return this->seats;
    }

    double getTotalAmount() {
        return this->totalAmount;
    }

    BookingStatus getStatus() {
        return this->status;
    }

    void confirm() {
        this->status = CONFIRMED;
    }

    void cancel() {
        this->status = CANCELLED;
    }
};

int Booking::nextBookingId = 1001;