#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cinema
{
private:
    string name;
    vector<Screen> screens;

public:

    Cinema()
    {
        name = "";
    }

    Cinema(string name)
    {
        this->name = name;
    }

    void addScreen(Screen screen)
    {
        screens.push_back(screen);
    }

    vector<Screen>& getScreens()
    {
        return screens;
    }

    string getName()
    {
        return name;
    }

    void listMovies()
    {
        cout << "Movies are currently available.\n";
    }
};