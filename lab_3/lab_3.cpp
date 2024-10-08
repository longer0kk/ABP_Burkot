// Variant 4

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int lab_3()
{
    const int size = 200;
    int Ar[size];
    int sumik = 0;
    srand(time(0));
    for (int i = 0; i < size; i++) 
    {
        Ar[i] = rand() % 101 - 50;
        cout << Ar[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < size - 1; i++) 
    {
        if (Ar[i] * Ar[i+1] < 0 || Ar[i] * Ar[i+1] == 0) 
        {
            sumik++;
        }
    }

    cout << "Kilkist' par z protilezh znakami: " << sumik << endl;
    return 0;
}