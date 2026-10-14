#include <iostream>
#include <string>
#include <limits>
using namespace std;
void showfortune(int choice){
    cout << "\n========== YOUR FORTUNE ==========\n";
    switch (choice)
    {
        case 1: cout << "A small opportunity may lead to something great.\n"; break;
        case 2: cout << "Stay curious; a new idea could change your direction.\n"; break;
        case 3: cout << "Your patience will be worth it. Keep going.\n"; break;
        case 4: cout << "A good conversation may bring a fresh perspective.\n"; break;
        case 5: cout << "Take the first step instead of waiting for the perfect moment.\n"; break;
        case 6: cout << "A challenge can teach you something valuable.\n"; break;
        case 7: cout << "Consistency will take you further than a burst of motivation.\n"; break;
        case 8: cout << "Make room for something new, and stay open to possibilities.\n"; break;
        default: cout << "Your future is yours to shape.\n"; break;
    }

    cout << "==================================\n";
}
string get_valid_color()
{
    string col;
    cout << "enter a color from given\nred\nyellow\nblack\ngreen\n";
    cin >> col;
    for (int i = 0;; i++)
    {
        if (col == "red" || col == "yellow" || col == "black" || col == "green")
        {
            return col;
        }
        else
        {
            cout << "That color is not on the list.\n";
            cout << "Enter a color from given\nred\nyellow\nblack\ngreen\n";
            cin >> col;
        }
    }
}
int valid_no(int min, int max)
{
    int choice;
    cout << "select your choice\nfrom " << min << "to" << max << endl;
    cin >> choice;
    for (int i = 0;; i++)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.";
            cin >> choice;
        }
        else if (choice >= min && choice <= max)
        {
            return choice;
        }
        else
        {
            cout << "That number is outside the allowed range.\n";
            cout << "select your choice\nfrom " << min << "to" << max << endl;
            cin >> choice;
        }
    }
}
int main()
{
    cout << "==================================\n";
    cout << "         DIGITAL FORTUNE TELLER   \n";
    cout << "==================================\n";
    cout << "Pick your color and numbers to reveal a fun fortune.\n\n";
    string col = get_valid_color();
    int choice;
    if (col == "red" || col == "black")
    {
        choice = valid_no(1, 4);
        if (choice == 2 || choice == 4)
        {
            choice = valid_no(1, 4);
        }
        else
        {
            choice = valid_no(5, 8);
        }
    }
    else
    {
        choice = valid_no(5, 8);
        if (choice == 6 || choice == 8)
        {
            choice = valid_no(1, 4);
        }
        else
        {
            choice = valid_no(5, 8);
        }
    }
    showfortune(choice);
    cout << "Thanks for playing the Digital Fortune Teller!\n";

    return 0;
}