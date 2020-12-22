// ascii-timer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

bool NumberHasFourDigits(int number);
void InputWhileCorrect(int& number);
void WhichAsciiToUse(int number, int row);
void ASCII_Zero(int row);
void ASCII_One(int row);
void ASCII_Two(int row);
void ASCII_Three(int row);
void ASCII_Four(int row);
void ASCII_Five(int row);
void ASCII_Six(int row);
void ASCII_Seven(int row);
void ASCII_Eight(int row);
void ASCII_Nine(int row);
void PrintColon(int row);


int main()
{
    int startingInput;
    InputWhileCorrect(startingInput);

    while (!NumberHasFourDigits(startingInput))
    {
        cout << "Input must have exactly four digits.\n";
        InputWhileCorrect(startingInput);
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
            //cout << minutes / 10 << endl;
            //cout << minutes % 10 << endl;
            //cout << seconds / 10 << endl;
            //cout << seconds % 10 << endl;
            WhichAsciiToUse(minutes / 100, i);
            cout << " ";
            WhichAsciiToUse(minutes % 100 / 10, i);
            cout << " ";
            WhichAsciiToUse(minutes % 10, i);
            PrintColon(i);
            WhichAsciiToUse(seconds / 10, i);
            cout << " ";
            WhichAsciiToUse(seconds % 10, i);
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

bool NumberHasFourDigits(int number)
{
    int counter = 0;
    while (number > 0)
    {
        number /= 10;
        counter++;
    }

    return (counter == 4) ? true : false;
}

void InputWhileCorrect(int& number)
{
    while (!(cin >> number) || number < 0)
    {
        cout << "Input a positive integer with exactly four digits.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void WhichAsciiToUse(int number, int row)
{
    switch (number)
    {
    case 0: ASCII_Zero(row); break;
    case 1: ASCII_One(row); break;
    case 2: ASCII_Two(row); break;
    case 3: ASCII_Three(row); break;
    case 4: ASCII_Four(row); break;
    case 5: ASCII_Five(row); break;
    case 6: ASCII_Six(row); break;
    case 7: ASCII_Seven(row); break;
    case 8: ASCII_Eight(row); break;
    case 9: ASCII_Nine(row); break;
    }
}

void ASCII_Zero(int row)
{
    switch (row)
    {
    case 1: cout << " #$#$#$#$  "; break;
    case 2: cout << "#$#$#$#$#$#"; break;
    case 3: cout << "$#$     $#$"; break;
    case 4: cout << "#$#     #$#"; break;
    case 5: cout << "$#$     $#$"; break;
    case 6: cout << "#$#     #$#"; break;
    case 7: cout << "$#$     $#$"; break;
    case 8: cout << "#$#     #$#"; break;
    case 9: cout << "$#$#$#$#$#$"; break;
    case 10:cout << " $#$#$#$#$ "; break;
    }
}

void ASCII_One(int row)
{
    switch (row)
    {
        case 1: cout << "     $$  "; break;
        case 2: cout << "    $#$  "; break;
        case 3: cout << "   $#$#  "; break;
        case 4: cout << "  $# #$  "; break;
        case 5: cout << " $#  $#  "; break;
        case 6: cout << "$#   #$  "; break;
        case 7: cout << "     $#  "; break;
        case 8: cout << "     #$  "; break;
        case 9: cout << "     $#  "; break;
        case 10:cout << "   #$#$#$"; break;
    }
}

void ASCII_Two(int row)
{
    switch (row)
    {
    case 1: cout << " $#$#$#$#  "; break;
    case 2: cout << "$#$#$#$#$# "; break;
    case 3: cout << "$      $#$ "; break;
    case 4: cout << "      #$#  "; break;
    case 5: cout << "     $#$   "; break;
    case 6: cout << "    #$#    "; break;
    case 7: cout << "   $#$     "; break;
    case 8: cout << "  #$#      "; break;
    case 9: cout << "$#$     #$ "; break;
    case 10:cout << "$#$#$#$#$#$"; break;
    }
}

void ASCII_Three(int row)
{
    switch (row)
    {
    case 1: cout << " $#$#$#$#$ "; break;
    case 2: cout << "$#$#$#$#$#$"; break;
    case 3: cout << "$       #$#"; break;
    case 4: cout << "       $#$ "; break;
    case 5: cout << "  #$#$#$#$ "; break;
    case 6: cout << "  $#$#$#$# "; break;
    case 7: cout << "       #$# "; break;
    case 8: cout << "$       $#$"; break;
    case 9: cout << "#$#$#$#$#$#"; break;
    case 10:cout << " #$#$#$#$# "; break;
    }
}

void ASCII_Four(int row)
{
    switch (row)
    {
    case 1: cout << "      $#$  "; break;
    case 2: cout << "     $#$#  "; break;
    case 3: cout << "    $#$#$  "; break;
    case 4: cout << "   $#$#$#  "; break;
    case 5: cout << "  $#$ $#$  "; break;
    case 6: cout << " $#$  #$#  "; break;
    case 7: cout << "$#$   $#$#$"; break;
    case 8: cout << "#$#$#$#$#$#"; break;
    case 9: cout << "     #$#   "; break;
    case 10:cout << "    #$#$#  "; break;
    }
}

void ASCII_Five(int row)
{
    switch (row)
    {
    case 1: cout << "#$#$#$#$#$#"; break;
    case 2: cout << "$#$#$#$#$#$"; break;
    case 3: cout << "#$         "; break;
    case 4: cout << "$#$        "; break;
    case 5: cout << "#$#$#$     "; break;
    case 6: cout << " #$#$#$#$  "; break;
    case 7: cout << "       $#$ "; break;
    case 8: cout << "        $#$"; break;
    case 9: cout << "#$     $#$ "; break;
    case 10:cout << " #$#$#$#$  "; break;
    }
}

void ASCII_Six(int row)
{
    switch (row)
    {
    case 1: cout << "  $#$#$#$  "; break;
    case 2: cout << " $#$#$#$#$ "; break;
    case 3: cout << "$#$      $ "; break;
    case 4: cout << "#$#        "; break;
    case 5: cout << "$#$#$#$#$  "; break;
    case 6: cout << "#$#$#$#$#$ "; break;
    case 7: cout << "$#$     #$#"; break;
    case 8: cout << "#$#     $#$"; break;
    case 9: cout << "$#$     #$#"; break;
    case 10:cout << " $#$#$#$#$ "; break;
    }
}

void ASCII_Seven(int row)
{
    switch (row)
    {
    case 1: cout << "$#$#$#$#$#$"; break;
    case 2: cout << "#$#$#$#$#$#"; break;
    case 3: cout << "$#     #$# "; break;
    case 4: cout << "      #$#  "; break;
    case 5: cout << "     #$#   "; break;
    case 6: cout << "    #$#    "; break;
    case 7: cout << "   #$#     "; break;
    case 8: cout << "  #$#      "; break;
    case 9: cout << " #$#       "; break;
    case 10:cout << "#$#        "; break;
    }
}

void ASCII_Eight(int row)
{
    switch (row)
    {
    case 1: cout << " #$#$#$#$# "; break;
    case 2: cout << "#$#$#$#$#$#"; break;
    case 3: cout << "$#$     $#$"; break;
    case 4: cout << "#$#     #$#"; break;
    case 5: cout << " #$#$#$#$# "; break;
    case 6: cout << " $#$#$#$#$ "; break;
    case 7: cout << "$#$     $#$"; break;
    case 8: cout << "#$#     #$#"; break;
    case 9: cout << "$#$#$#$#$#$"; break;
    case 10:cout << " $#$#$#$#$ "; break;
    }
}

void ASCII_Nine(int row)
{
    switch (row)
    {
    case 1: cout << " $#$#$#$#  "; break;
    case 2: cout << "$#$#$#$#$# "; break;
    case 3: cout << "#$#     #$#"; break;
    case 4: cout << "$#$     $#$"; break;
    case 5: cout << "#$#$#$#$#$#"; break;
    case 6: cout << " #$#$#$#$#$"; break;
    case 7: cout << "        #$#"; break;
    case 8: cout << "        $#$"; break;
    case 9: cout << "$#      #$#"; break;
    case 10:cout << " #$#$#$#$# "; break;
    }
}

void PrintColon(int row)
{
    switch (row)
    {
    case 1: cout << "   "; break;
    case 2: cout << "   "; break;
    case 3: cout << " # "; break;
    case 4: cout << " # "; break;
    case 5: cout << "   "; break;
    case 6: cout << "   "; break;
    case 7: cout << " # "; break;
    case 8: cout << " # "; break;
    case 9: cout << "   "; break;
    case 10:cout << "   "; break;
    }
}
