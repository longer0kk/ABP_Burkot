// Variant 4

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void n1_lab5(int* Ar, int size)
{
    srand(time(0));
    
    for (int i = 0; i < size; i++) 
    {
        Ar[i] = rand() % 101 - 50;
        cout << Ar[i] << " ";
    }
    cout << endl;
}

void n2_lab5(int* Ar, int size)
{
    cout << "Dianky z sumoyu 0:" << endl;
    bool found = false;

    for (int start = 0; start < size; start++) 
    {
        int sum = 0;
        for (int end = start; end < size; end++) 
        {
            sum += Ar[end];
            if (sum == 0) 
            {
                found = true;
                cout << "Vid indeksu " << start << " do " << end << endl;
            }
        }
    }
    
    if (!found) 
    {
        cout << "Nemaye diyanok z sumoyu 0." << endl;
    }
}

int lab_5()
{
    int size;
    cout << "Input size: ";
    cin >> size;
    
    int* Ar = new int[size];
    n1_lab5(Ar, size);
    n2_lab5(Ar, size);

    return 0;
}