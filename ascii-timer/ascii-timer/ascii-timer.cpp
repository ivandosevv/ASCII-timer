// ascii-timer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    int startingInput;

    while (!(cin>> startingInput) || startingInput < 0)
    {
        cout << "Input a positive integer!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int minutes, seconds;
    minutes = startingInput / 60;
    seconds = startingInput % 60;

    while (minutes >= 0 && seconds >= 0)
    {
        cout << minutes << ":";
        if (seconds < 10)
        {
            cout << "0";
        }
        cout << seconds << endl;

        if (seconds == 0)
        {
            minutes--;
            seconds = 59;
        }
        else
        {
            seconds--;
        }

        std::chrono::milliseconds timespan(1000);
        std::this_thread::sleep_for(timespan);
    }
    
    
    cout << '\a';
    system("pause");
}

