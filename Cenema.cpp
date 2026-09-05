#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Temporary Screen definition for understanding.
// It will be connected to Screen.cpp in the final project.

class Screen {
private:
    int screenNumber;

public:
    Screen(int screenNumber) {
        this->screenNumber = screenNumber;
    }

    int getScreenNumber() {
        return this->screenNumber;
    }
};

class Cinema {
private:
    string name;
    vector<Screen> screens;

public:
    Cinema(string name) {
        this->name = name;
    }

    void addScreen(Screen screen) {
        this->screens.push_back(screen);
    }

    vector<Screen> getScreens() {
        return this->screens;
    }

    string getName() {
        return this->name;
    }

    void listMovies() {
        cout << "Movie listing will be connected with Show module." << endl;
    }
};