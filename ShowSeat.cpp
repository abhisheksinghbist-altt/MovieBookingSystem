#include <iostream>
using namespace std;

enum SeatStatus
{
    AVAILABLE,
    BOOKED
};

class ShowSeat
{
private:
    Seat* seat;
    SeatStatus status;

public:

    ShowSeat()
    {
        seat = nullptr;
        status = AVAILABLE;
    }

    ShowSeat(Seat* seat)
    {
        this->seat = seat;
        status = AVAILABLE;
    }

    bool isAvailable()
    {
        return status == AVAILABLE;
    }

    bool bookSeat()
    {
        if (status == BOOKED)
            return false;

        status = BOOKED;
        return true;
    }

    void cancelSeat()
    {
        status = AVAILABLE;
    }

    Seat* getSeat()
    {
        return seat;
    }

    SeatStatus getStatus()
    {
        return status;
    }
};