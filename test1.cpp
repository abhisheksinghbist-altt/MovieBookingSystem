#include <iostream>
#include <string>
using namespace std;

enum SeatType {
    SILVER,
    GOLD,
    PLATINUM
};

class Movie {
private:
    string title;
    string language;
    int duration;

public:
    Movie() {
        this->title = "";
        this->language = "";
        this->duration = 0;
    }

    Movie(string title, string language, int duration) {
        this->title = title;
        this->language = language;
        this->duration = duration;
    }

    string getTitle() {
        return this->title;
    }

    string getLanguage() {
        return this->language;
    }

    int getDuration() {
        return this->duration;
    }
};

class Seat {
private:
    int seatNumber;
    SeatType type;

public:
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

        if (this->type == SILVER)
            return SILVER_PRICE;

        if (this->type == GOLD)
            return GOLD_PRICE;

        return PLATINUM_PRICE;
    }
};

int main() {

    Movie movie(
        "Avengers: Endgame",
        "English",
        181
    );

    Seat seat1(1, GOLD);

    cout << "Movie: " << movie.getTitle() << endl;
    cout << "Language: " << movie.getLanguage() << endl;
    cout << "Duration: " << movie.getDuration() << " minutes" << endl;

    cout << endl;

    cout << "Seat Number: " << seat1.getSeatNumber() << endl;
    cout << "Seat Price: Rs. " << seat1.getPrice() << endl;

    return 0;
}