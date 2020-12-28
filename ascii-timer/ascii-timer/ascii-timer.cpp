/**
*
* Solution to course project # 10
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Dosev
* @idnumber 62611
* @compiler VC
*
* <file with main and helper functions>
*
*/


#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

bool NumberHasFourDigits(int number);
int NumberOfDigitsInNumber(int number);
int InputWhileCorrect();
void WhichAsciiToUse(int number, int row);
void CenterHeight();
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
void PrintWelcomeMessage();

int main()
{
    const int MAX_ROWS = 25;
    const int MAX_COLS = 80;

    // Set the console's resolution to 80x25.
    system("MODE 80,25");
    
    PrintWelcomeMessage();

    // startingInput gets the first correct input we enter.
    // Since the requirements for the project state, that we enter a 4-digit number,
    // then the timer won't start until we do exactly that.
    int startingInput = InputWhileCorrect();

    // If we have successfully entered a number, then we check if it has exactly four digits.
    while (!NumberHasFourDigits(startingInput))
    {
        // Cleans console.
        system("cls");

        const int CENTER_OUTPUT_MESSAGE = 55;

        cout << "\n\n\n\n\n" << setw(CENTER_OUTPUT_MESSAGE) << "Input must have exactly four digits: ";
        startingInput = InputWhileCorrect();
    }

    // Get the values of the minutes and seconds.
    const int SECONDS_IN_A_MINUTE = 60;

    int minutes, seconds;
    minutes = startingInput / SECONDS_IN_A_MINUTE;
    seconds = startingInput % SECONDS_IN_A_MINUTE;

    // We start counting backwards until we've reached 0:00.
    while (minutes >= 0 && seconds >= 0)
    {
        // Cleans console.
        system("cls");
        
        // Outputs empty spaces, so that we can center our timer.
        CenterHeight();

        for (int i = 1; i <= 10; i++)
        {
            int numberOfDigitsInMinutes = NumberOfDigitsInNumber(minutes);

            // We check how many digits the minute number has, so we know
            // exactly how to center it and use the needed ASCII art.
            if (numberOfDigitsInMinutes == 3)
            {
                const int CENTER_TIMER = 20;

                cout << setw(CENTER_TIMER);

                WhichAsciiToUse(minutes / 100, i);
                cout << " ";
                WhichAsciiToUse(minutes % 100 / 10, i);
                cout << " ";
            }
            else if (numberOfDigitsInMinutes == 2)
            {
                const int CENTER_TIMER = 27;

                cout << setw(CENTER_TIMER);

                WhichAsciiToUse(minutes / 10, i);
                cout << " ";
            }
            else
            {
                const int CENTER_TIMER = 30;

                cout << setw(CENTER_TIMER);
            }

            // These functions are universal, because it doesn't matter how big
            // the input is, we'll always use these three numbers.
            // The last digit of the minute number and the seconds.
            WhichAsciiToUse(minutes % 10, i);
            PrintColon(i);
            WhichAsciiToUse(seconds / 10, i);
            cout << " ";
            WhichAsciiToUse(seconds % 10, i);
            cout << endl;
        }

        // If we have reached the end of the seconds, then we start again and reduce
        // one from the minutes.
        if (seconds == 0)
        {
            minutes--;
            seconds = 59;
        }
        else
        {
            seconds--;
        }
        
        CenterHeight();

        // We use these functions, so that we can let the timer stop for a 
        // second (1000 milliseconds) before doing anything else.
        std::chrono::milliseconds timespan(1000);
        std::this_thread::sleep_for(timespan);
    }
    
    // Creates a sound when the timer has finished.
    cout << '\a';

    system("pause");
}

// Checks if the given number has EXACTLY 4 digits.
bool NumberHasFourDigits(int number)
{
    const int NEEDED_NUMBER_LENGTH = 4;

    int counter = 0;

    while (number > 0)
    {
        number /= 10;
        counter++;
    }

    // Uncomment to work with every number, that's smaller than 60000.
    //return true;

    return (counter == NEEDED_NUMBER_LENGTH) ? true : false;
}

// Checks the number of digits in the given number.
// We use it when we want to see how we want to center the timer
// according to the number of digits in the minute number.
int NumberOfDigitsInNumber(int number)
{
    int counter = 0;

    while (number > 0)
    {
        number /= 10;
        counter++;
    }

    return counter;
}

// Outputs a message until we enter a correct integer.
// We check if the number is bigger than 60000, because if we want to test
// the timer's ending faster, rather than wait 16 minutes, then we must not input a number
// that will make the number of digits in the minutes more than 4.
// If we want to use that, then we must uncomment "return true;" 
// in the @bool NumberHasFourDigits(int number) function.
int InputWhileCorrect()
{
    const int CENTER_OUTPUT_MESSAGE = 60;

    int number;

    while (!(cin >> number) || number < 0 || number >= 60000)
    {
        // Clears console.
        system("cls");

        cout << "\n\n\n\n\n" << setw(CENTER_OUTPUT_MESSAGE) << "Input a positive integer with exactly four digits: ";
        
        // Clears the error.
        cin.clear();

        // Ignores everything until '\n'. The "::max()" part tells the program that there is no limit
        // to how many characters to ignore and only starts reading after we click "Enter".
        // We do this, because if the input is not correct, then we want to enter again, until we
        // have given the program a correctly formatted input.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return number;
}

// Inputs new lines, until the timer is centered.
void CenterHeight()
{
    const int MAX_ROWS = 25;
    const int MAX_COLS = 80;

    const int ROWS_TO_SKIP = (MAX_ROWS - 10) / 2;

    for (int i = 0; i < ROWS_TO_SKIP; i++)
    {
        cout << endl;
    }
}

// Decides which ASCII art to use according to the current number.
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

// Prints a line of ASCII zero, depending on the current row.
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

// Prints a line of ASCII one, depending on the current row.
void ASCII_One(int row)
{
    switch (row)
    {
	    case 1: cout << "      $$   "; break;
	    case 2: cout << "     $#$   "; break;
	    case 3: cout << "    $#$#   "; break;
	    case 4: cout << "   $# #$   "; break;
	    case 5: cout << "  $#  $#   "; break;
	    case 6: cout << " $#   #$   "; break;
	    case 7: cout << "$#    $#   "; break;
	    case 8: cout << "      #$   "; break;
	    case 9: cout << "      $#   "; break;
	    case 10:cout << "   $#$#$#$#"; break;
    }
}

// Prints a line of ASCII two, depending on the current row.
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

// Prints a line of ASCII three, depending on the current row.
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

// Prints a line of ASCII four, depending on the current row.
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

// Prints a line of ASCII five, depending on the current row.
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

// Prints a line of ASCII six, depending on the current row.
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

// Prints a line of ASCII seven, depending on the current row.
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

// Prints a line of ASCII eight, depending on the current row.
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

// Prints a line of ASCII nine, depending on the current row.
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

// Prints a line of ASCII colon, depending on the current row.
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

// Prints a welcome message at the beginning of the program.
void PrintWelcomeMessage()
{
    const int CENTER_OUTPUT_MESSAGE = 50;

    cout << "  _                _  _____  __     /~~~~~~\\/******\\    \\\\   //    __________" << endl;
    cout << "  \\\\              //||    |||~|     |/-----|| #### |    //   \\\\    |/////////\\" << endl;
    cout << "   \\\\     ~~     // ||      |~|     ||      | |  | |   /\\\\   //\\   |\\\\_____" << endl;
    cout << "    \\\\   //\\\\   //  ||~~~~~>|~|     ||      | |  | |  // \\\\ // \\\\  |///////\\" << endl;
    cout << "     \\\\ //  \\\\ //   ||      |~|____ |\\-----|| #### | //   \\//   \\\\ |\\\\_______" << endl;
    cout << "      \\//    \\\\/    ||____|||______|\\~~~~~~/\\******///           \\\\|/////////\\" << endl;
    cout << "\n\n" << setw(CENTER_OUTPUT_MESSAGE) << "Input a 4 digit number: ";
}

