#include <iostream>
using namespace std;

class TicketPrinter
{
public:
    void printTicket(Booking* booking)
    {
        cout << "\n========== MOVIE TICKET ==========" << endl;

        cout << "Booking ID: "
             << booking->getBookingId() << endl;

        cout << "Movie: "
             << booking->getShow()->getMovie()->getTitle()
             << endl;

        cout << "Screen: "
             << booking->getShow()->getScreen()->getScreenNumber()
             << endl;

        cout << "Time: "
             << booking->getShow()->getStartTime()
             << endl;

        cout << "Seats: ";

        for (ShowSeat* showSeat : booking->getSeats())
        {
            cout << showSeat->getSeat()->getSeatNumber()
                 << " ";
        }

        cout << endl;

        cout << "Total Amount: Rs. "
             << booking->getTotalAmount()
             << endl;

        cout << "==================================" << endl;
    }
};