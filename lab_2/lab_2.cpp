// Variant 4

#include <iostream>
#include <iomanip>

using namespace std;

double x, y;

void YesOrNah(double x, double y)
{
    bool UpperOne = (y >= 0) && (y <= 1) && (y >= x) && (y >= -x);
    bool DownOne = (y <= 0) && (y >= -1) && (y <= x) && (y <= -x);

    if (UpperOne || DownOne) {
        cout << "The point (" << x << ", " << y << ") is inside the shaded area.\n";
    }
    else {
        cout << "The point (" << x << ", " << y << ") is outside the shaded area.\n";
    }
}


int lab_2()
{

    int menu;

    do
    {
        cout << "Menu\n";
        cout << "1. Input your cordinates\n";
        cout << "2. Results\n";
        cout << "3. Exit\n";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Enter x coordinate: ";
            cin >> x;
            cout << "Enter y coordinate: ";
            cin >> y;
            break;

        case 2:
            YesOrNah(x, y);
            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Incorrect number, try something else";
            break;
        }
    } while (menu != 3);

    return 0;
}