#include <iostream>
#include <vector>
using namespace std;

class Screen
{
private:
    int screenNumber;
    vector<Seat> seats;

public:

    Screen()
    {
        screenNumber = 0;
    }

    Screen(int screenNumber)
    {
        this->screenNumber = screenNumber;
    }

    void addSeat(Seat seat)
    {
        seats.push_back(seat);
    }

    vector<Seat>& getSeats()
    {
        return seats;
    }

    int getScreenNumber()
    {
        return screenNumber;
    }
};