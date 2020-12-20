// ascii-timer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void WhichAsciiToUse(int number, int row);
void ASCII_One(int row);
void ASCII_Two(int row);
void ASCII_Three(int row);
void ASCII_Four(int row);

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
        // Cleans console.
        system("cls");

        cout << minutes << ":";
        if (seconds < 10)
        {
            cout << "0";
        }
        cout << seconds << endl;

        for (int i = 1; i <= 10; i++)
        {
            WhichAsciiToUse(minutes, i);
            WhichAsciiToUse(seconds, i);
            cout << endl;
        }

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

void WhichAsciiToUse(int number, int row)
{
    switch (number)
    {
        //case 0: ASCII_Zero()
    case 1: ASCII_One(row); break;
    case 2: ASCII_Two(row); break;
    case 3: ASCII_Three(row); break;
    case 4: ASCII_Four(row); break;
        default: 
        {

        }
    }
}

void ASCII_One(int row)
{
    switch (row)
    {
        case 1: cout << "  @@@"; break;
        case 2: cout << " @@@@"; break;
        case 3: cout << "@@@!!"; break;
        case 4: cout << "  !@!"; break;
        case 5: cout << "  @!@"; break;
        case 6: cout << "  !@!"; break;
        case 7: cout << "  !!:"; break;
        case 8: cout << "  :!:"; break;
        case 9: cout << "  :::"; break;
        case 10:cout << "   ::"; break;
    }
}

void ASCII_Two(int row)
{
    switch (row)
    {
    case 1: cout << " @@@@@@ "; break;
    case 2: cout << "@@@@@@@@"; break;
    case 3: cout << "     @@@"; break;
    case 4: cout << "    @!@ "; break;
    case 5: cout << "   !!@  "; break;
    case 6: cout << "  !!:   "; break;
    case 7: cout << " !:!    "; break;
    case 8: cout << ":!:     "; break;
    case 9: cout << ":: :::::"; break;
    case 10:cout << ":: : :::"; break;
    }
}

void ASCII_Three(int row)
{
    switch (row)
    {
    case 1: cout << "@@@@@@ "; break;
    case 2: cout << "@@@@@@@"; break;
    case 3: cout << "    @@@"; break;
    case 4: cout << "    @!@"; break;
    case 5: cout << "@!@!!@ "; break;
    case 6: cout << "!!@!@! "; break;
    case 7: cout << "    !!:"; break;
    case 8: cout << "    :!:"; break;
    case 9: cout << ":: ::::"; break;
    case 10:cout << " : : : "; break;
    }
}

void ASCII_Four(int row)
{
    switch (row)
    {
    case 1: cout << "     @@@ "; break;
    case 2: cout << "    @@@@ "; break;
    case 3: cout << "   @@!@! "; break;
    case 4: cout << "  !@!!@! "; break;
    case 5: cout << " @!! @!! "; break;
    case 6: cout << "!!!  !@! "; break;
    case 7: cout << ":!!:!:!!:"; break;
    case 8: cout << "!:::!!:::"; break;
    case 9: cout << "     ::: "; break;
    case 10:cout << "     ::: "; break;
    }
}

