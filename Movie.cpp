#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string language;
    int duration;

public:
    // Compile-time polymorphism: overloaded constructors
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