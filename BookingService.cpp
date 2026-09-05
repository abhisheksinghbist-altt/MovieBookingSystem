
#include <iostream>
#include <vector>
using namespace std;

class BookingService
{
private:
    vector<Booking*> bookings;

public:

    BookingService()
    {
    }

    void addBooking(Booking* booking)
    {
        bookings.push_back(booking);
    }

    Booking* findBooking(int bookingId)
    {
        for (Booking* booking : bookings)
        {
            if (booking->getBookingId() == bookingId)
            {
                return booking;
            }
        }

        return nullptr;
    }

    Booking* bookTicket(
        Show* show,
        vector<ShowSeat*> selectedSeats)
    {
        // Check all selected seats
        for (ShowSeat* showSeat : selectedSeats)
        {
            if (!showSeat->isAvailable())
            {
                cout << "Seat "
                     << showSeat->getSeat()->getSeatNumber()
                     << " is already booked." << endl;

                return nullptr;
            }
        }

        // Book all selected seats
        for (ShowSeat* showSeat : selectedSeats)
        {
            showSeat->bookSeat();
        }

        // Calculate total amount
        PriceCalculator calculator;

        double totalAmount =
            calculator.calculateTotal(selectedSeats);

        // Create booking
        Booking* booking =
            new Booking(show, selectedSeats, totalAmount);

        cout << "Booking initiated successfully."
             << endl;

        return booking;
    }

    bool processPayment(
        Booking* booking,
        Payment* payment)
    {
        double amount =
            booking->getTotalAmount();

        bool paymentSuccessful =
            payment->pay(amount);

        if (paymentSuccessful)
        {
            booking->confirm();

            addBooking(booking);

            cout << "Payment successful."
                 << endl;

            cout << "Booking confirmed."
                 << endl;

            return true;
        }

        cout << "Payment failed."
             << endl;

        releaseSeats(booking);

        booking->cancel();

        cout << "Booking not confirmed."
             << endl;

        return false;
    }

    void releaseSeats(Booking* booking)
    {
        vector<ShowSeat*> seats =
            booking->getSeats();

        for (ShowSeat* showSeat : seats)
        {
            showSeat->cancelSeat();
        }

        cout << "Selected seats are available again."
             << endl;
    }

    bool cancelBooking(int bookingId)
    {
        Booking* booking =
            findBooking(bookingId);

        if (booking == nullptr)
        {
            cout << "Booking not found."
                 << endl;

            return false;
        }

        if (booking->getStatus() != CONFIRMED)
        {
            cout << "Booking cannot be cancelled."
                 << endl;

            return false;
        }

        releaseSeats(booking);

        booking->cancel();

        cout << "Booking cancelled successfully."
             << endl;

        return true;
    }
};
