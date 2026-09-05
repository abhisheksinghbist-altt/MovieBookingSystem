#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Show
{
private:
    Movie* movie;
    Screen* screen;
    string startTime;
    vector<ShowSeat> showSeats;

public:

    Show()
    {
        movie = nullptr;
        screen = nullptr;
        startTime = "";
    }

    Show(Movie* movie, Screen* screen, string startTime)
    {
        this->movie = movie;
        this->screen = screen;
        this->startTime = startTime;
    }

    Movie* getMovie()
    {
        return movie;
    }

    Screen* getScreen()
    {
        return screen;
    }

    string getStartTime()
    {
        return startTime;
    }

    vector<ShowSeat>& getShowSeats()
    {
        return showSeats;
    }

    void addShowSeat(ShowSeat showSeat)
    {
        showSeats.push_back(showSeat);
    }

    void showSeatsLayout()
    {
        cout << "\n--- SEAT LAYOUT ---\n";

        for (ShowSeat& showSeat : showSeats)
        {
            cout << "Seat "
                 << showSeat.getSeat()->getSeatNumber()
                 << " : ";

            if (showSeat.isAvailable())
                cout << "AVAILABLE";
            else
                cout << "BOOKED";

            cout << endl;
        }
    }
};