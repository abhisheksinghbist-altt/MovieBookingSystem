#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Show {
};

class ShowSeat {
};

class Customer {
private:
    string name;
    string phone;

public:
    Customer(string name, string phone) {
        this->name = name;
        this->phone = phone;
    }

    string getName() {
        return this->name;
    }

    string getPhone() {
        return this->phone;
    }
};

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

    int getBookingId() {
        return this->bookingId;
    }

    double getTotalAmount() {
        return this->totalAmount;
    }

    void confirm() {
        this->status = CONFIRMED;
    }

    void cancel() {
        this->status = CANCELLED;
    }
};

int Booking::nextBookingId = 1001;

int main() {

    Customer customer(
        "Abhishek",
        "9876543210"
    );

    Show show;

    vector<ShowSeat*> selectedSeats;

    Booking booking(
        &show,
        selectedSeats,
        250
    );

    cout << "Customer: "
         << customer.getName() << endl;

    cout << "Phone: "
         << customer.getPhone() << endl;

    cout << "Booking ID: "
         << booking.getBookingId() << endl;

    cout << "Amount: Rs. "
         << booking.getTotalAmount() << endl;

    booking.confirm();

    cout << "Booking confirmed successfully."
         << endl;

    return 0;
}