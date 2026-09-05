#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ========================================
// CONNECT ALL MODULES
// ========================================

#include "Movie.cpp"
#include "Seat.cpp"
#include "Screen.cpp"
#include "Cinema.cpp"
#include "ShowSeat.cpp"
#include "Show.cpp"
#include "Customer.cpp"
#include "Booking.cpp"

#include "Payment.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"

#include "PriceCalculator.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"


int main()
{
    // ========================================
    // CREATE MOVIES
    // ========================================

    Movie movie1(
        "Avengers: Endgame",
        "English",
        181);

    Movie movie2(
        "3 Idiots",
        "Hindi",
        170);


    // ========================================
    // CREATE SCREENS
    // ========================================

    Screen screen1(1);
    Screen screen2(2);


    // ========================================
    // CREATE SEATS
    // ========================================

    // Screen 1
    for (int i = 1; i <= 3; i++)
        screen1.addSeat(Seat(i, SILVER));

    for (int i = 4; i <= 6; i++)
        screen1.addSeat(Seat(i, GOLD));

    for (int i = 7; i <= 8; i++)
        screen1.addSeat(Seat(i, PLATINUM));


    // Screen 2
    for (int i = 1; i <= 3; i++)
        screen2.addSeat(Seat(i, SILVER));

    for (int i = 4; i <= 6; i++)
        screen2.addSeat(Seat(i, GOLD));

    for (int i = 7; i <= 8; i++)
        screen2.addSeat(Seat(i, PLATINUM));


    // ========================================
    // CREATE CINEMA
    // ========================================

    Cinema cinema("PVR Cinema");

    cinema.addScreen(screen1);
    cinema.addScreen(screen2);


    // ========================================
    // CREATE SHOWS
    // ========================================

    Show show1(
        &movie1,
        &screen1,
        "06:00 PM");

    Show show2(
        &movie1,
        &screen2,
        "09:00 PM");

    Show show3(
        &movie2,
        &screen1,
        "03:00 PM");


    // ========================================
    // CREATE SHOW SEATS
    // ========================================

    vector<Seat>& seats1 = screen1.getSeats();

    for (Seat& seat : seats1)
        show1.addShowSeat(ShowSeat(&seat));

    for (Seat& seat : seats1)
        show3.addShowSeat(ShowSeat(&seat));


    vector<Seat>& seats2 = screen2.getSeats();

    for (Seat& seat : seats2)
        show2.addShowSeat(ShowSeat(&seat));


    // ========================================
    // CREATE SERVICES
    // ========================================

    BookingService bookingService;
    TicketPrinter ticketPrinter;


    // ========================================
    // MAIN MENU
    // ========================================

    int choice;

    do
    {
        cout << "\n";
        cout << "============================================\n";
        cout << "       MOVIE TICKET BOOKING SYSTEM\n";
        cout << "============================================\n";
        cout << "1. List Movies Currently Playing\n";
        cout << "2. List Shows for a Movie\n";
        cout << "3. Display Seat Layout\n";
        cout << "4. Book Ticket\n";
        cout << "5. Print Ticket\n";
        cout << "6. Cancel Booking\n";
        cout << "7. Exit\n";
        cout << "============================================\n";

        cout << "Enter your choice: ";
        cin >> choice;


        // ====================================
        // OPTION 1 - LIST MOVIES
        // ====================================

        if (choice == 1)
        {
            cout << "\n--- CURRENTLY PLAYING MOVIES ---\n";

            cout << "1. "
                 << movie1.getTitle()
                 << " | "
                 << movie1.getLanguage()
                 << " | "
                 << movie1.getDuration()
                 << " minutes\n";

            cout << "2. "
                 << movie2.getTitle()
                 << " | "
                 << movie2.getLanguage()
                 << " | "
                 << movie2.getDuration()
                 << " minutes\n";
        }


        // ====================================
        // OPTION 2 - LIST SHOWS
        // ====================================

        else if (choice == 2)
        {
            int movieChoice;

            cout << "\nSelect Movie:\n";
            cout << "1. " << movie1.getTitle() << endl;
            cout << "2. " << movie2.getTitle() << endl;

            cout << "Enter choice: ";
            cin >> movieChoice;

            if (movieChoice == 1)
            {
                cout << "\nShows for "
                     << movie1.getTitle() << ":\n";

                cout << "1. Screen "
                     << show1.getScreen()->getScreenNumber()
                     << " - "
                     << show1.getStartTime()
                     << endl;

                cout << "2. Screen "
                     << show2.getScreen()->getScreenNumber()
                     << " - "
                     << show2.getStartTime()
                     << endl;
            }
            else if (movieChoice == 2)
            {
                cout << "\nShows for "
                     << movie2.getTitle() << ":\n";

                cout << "1. Screen "
                     << show3.getScreen()->getScreenNumber()
                     << " - "
                     << show3.getStartTime()
                     << endl;
            }
            else
            {
                cout << "Invalid movie choice.\n";
            }
        }


        // ====================================
        // OPTION 3 - DISPLAY SEAT LAYOUT
        // ====================================

        else if (choice == 3)
        {
            int movieChoice;

            cout << "\nSelect Movie:\n";
            cout << "1. " << movie1.getTitle() << endl;
            cout << "2. " << movie2.getTitle() << endl;

            cout << "Enter choice: ";
            cin >> movieChoice;

            if (movieChoice == 1)
            {
                int showChoice;

                cout << "\nAvailable Shows:\n";
                cout << "1. Screen 1 - 06:00 PM\n";
                cout << "2. Screen 2 - 09:00 PM\n";

                cout << "Select show: ";
                cin >> showChoice;

                if (showChoice == 1)
                    show1.showSeatsLayout();

                else if (showChoice == 2)
                    show2.showSeatsLayout();

                else
                    cout << "Invalid show choice.\n";
            }
            else if (movieChoice == 2)
            {
                cout << "\nShow: Screen 1 - 03:00 PM\n";
                show3.showSeatsLayout();
            }
            else
            {
                cout << "Invalid movie choice.\n";
            }
        }


        // ====================================
        // OPTION 4 - BOOK TICKET
        // ====================================

        else if (choice == 4)
        {
            int movieChoice;
            int showChoice;

            // Select Movie
            cout << "\nSelect Movie:\n";
            cout << "1. " << movie1.getTitle() << endl;
            cout << "2. " << movie2.getTitle() << endl;

            cout << "Enter choice: ";
            cin >> movieChoice;

            Show* selectedShow = nullptr;


            // Select Show
            if (movieChoice == 1)
            {
                cout << "\nAvailable Shows:\n";
                cout << "1. Screen 1 - 06:00 PM\n";
                cout << "2. Screen 2 - 09:00 PM\n";

                cout << "Select show: ";
                cin >> showChoice;

                if (showChoice == 1)
                    selectedShow = &show1;

                else if (showChoice == 2)
                    selectedShow = &show2;
            }
            else if (movieChoice == 2)
            {
                cout << "\nAvailable Shows:\n";
                cout << "1. Screen 1 - 03:00 PM\n";

                cout << "Select show: ";
                cin >> showChoice;

                if (showChoice == 1)
                    selectedShow = &show3;
            }
            else
            {
                cout << "Invalid movie choice.\n";
            }


            if (selectedShow == nullptr)
            {
                cout << "Invalid show selection.\n";
                continue;
            }


            // Display Seat Layout
            selectedShow->showSeatsLayout();


            // Select Number of Seats
            int numberOfSeats;

            cout << "\nHow many seats do you want? ";
            cin >> numberOfSeats;

            if (numberOfSeats <= 0)
            {
                cout << "Invalid number of seats.\n";
                continue;
            }


            vector<ShowSeat*> selectedSeats;

            bool selectionValid = true;


            // Select Seats
            for (int i = 0; i < numberOfSeats; i++)
            {
                int seatNumber;

                cout << "Enter seat number "
                     << i + 1 << ": ";

                cin >> seatNumber;

                bool found = false;

                for (ShowSeat& showSeat :
                     selectedShow->getShowSeats())
                {
                    if (showSeat.getSeat()->getSeatNumber()
                        == seatNumber)
                    {
                        found = true;

                        if (!showSeat.isAvailable())
                        {
                            cout << "Seat "
                                 << seatNumber
                                 << " is already booked.\n";

                            selectionValid = false;
                            break;
                        }


                        // Check duplicate seat selection
                        bool duplicate = false;

                        for (ShowSeat* selected :
                             selectedSeats)
                        {
                            if (selected->getSeat()
                                    ->getSeatNumber()
                                == seatNumber)
                            {
                                duplicate = true;
                                break;
                            }
                        }


                        if (duplicate)
                        {
                            cout << "Seat "
                                 << seatNumber
                                 << " selected twice.\n";

                            selectionValid = false;
                            break;
                        }


                        selectedSeats.push_back(&showSeat);
                        break;
                    }
                }


                if (!found)
                {
                    cout << "Invalid seat number.\n";
                    selectionValid = false;
                    break;
                }
            }


            if (!selectionValid)
                continue;


            // Create Booking
            Booking* booking =
                bookingService.bookTicket(
                    selectedShow,
                    selectedSeats);


            if (booking == nullptr)
                continue;


            cout << "\nTotal Amount: Rs. "
                 << booking->getTotalAmount()
                 << endl;


            // Select Payment
            int paymentChoice;

            cout << "\nSelect Payment Method:\n";
            cout << "1. UPI\n";
            cout << "2. Card\n";
            cout << "3. Cash\n";

            cout << "Enter choice: ";
            cin >> paymentChoice;


            Payment* payment = nullptr;


            if (paymentChoice == 1)
            {
                string upiId;

                cout << "Enter UPI ID: ";
                cin >> upiId;

                payment = new UpiPayment(upiId);
            }
            else if (paymentChoice == 2)
            {
                string cardNumber;

                cout << "Enter Card Number: ";
                cin >> cardNumber;

                payment = new CardPayment(cardNumber);
            }
            else if (paymentChoice == 3)
            {
                payment = new CashPayment();
            }
            else
            {
                cout << "Invalid payment method.\n";

                // Release seats
                for (ShowSeat* showSeat :
                     selectedSeats)
                {
                    showSeat->cancelSeat();
                }

                booking->cancel();

                delete booking;

                continue;
            }


            // Process Payment
            bool paymentSuccessful =
                bookingService.processPayment(
                    booking,
                    payment);


            delete payment;


            // Payment Result
            if (paymentSuccessful)
            {
                cout << "\nBooking completed successfully!\n";

                ticketPrinter.printTicket(booking);
            }
            else
            {
                cout << "\nPayment failed.\n";
                cout << "Booking was not confirmed.\n";
                cout << "Selected seats are available again.\n";

                delete booking;
            }
        }


        // ====================================
        // OPTION 5 - PRINT TICKET
        // ====================================

        else if (choice == 5)
        {
            int bookingId;

            cout << "\nEnter Booking ID: ";
            cin >> bookingId;

            Booking* booking =
                bookingService.findBooking(bookingId);


            if (booking == nullptr)
            {
                cout << "Booking not found.\n";
            }
            else if (booking->getStatus() != CONFIRMED)
            {
                cout << "Ticket cannot be printed.\n";
                cout << "Payment is not confirmed.\n";
            }
            else
            {
                ticketPrinter.printTicket(booking);
            }
        }


        // ====================================
        // OPTION 6 - CANCEL BOOKING
        // ====================================

        else if (choice == 6)
        {
            int bookingId;

            cout << "\nEnter Booking ID: ";
            cin >> bookingId;

            bookingService.cancelBooking(bookingId);
        }


        // ====================================
        // OPTION 7 - EXIT
        // ====================================

        else if (choice == 7)
        {
            cout << "\nThank you for using the system!\n";
        }


        // ====================================
        // INVALID OPTION
        // ====================================

        else
        {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);


    return 0;
}