// Variant 4

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Detail
{
    char name[12];
    char type;
    unsigned short amou;
    float wgh;
};

void input(Detail details[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i+1 << " Enter: name, type, amount, weight of detail > ";
        cin >> details[i].name >> details[i].type >> details[i].amou >> details[i].wgh;
    }
}

void sort(Detail details[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(details[i].name, details[j].name) > 0) {
                Detail temp = details[i];
                details[i] = details[j];
                details[j] = temp;
            }
        }
    }
}

void output(const Detail details[], int n)
{
    cout << "-------------------------------------------------------\n";
    cout << "|                Details information                  |\n";
    cout << "|-----------------------------------------------------|\n";
    cout << "|    Name   | Type |  Amount   |  Weight per item (g) |\n";
    cout << "|-----------|------|-----------|----------------------|\n";

    for (int i = 0; i < n; i++)
    {
        cout << "|" << setw(10) << details[i].name << " |  " << details[i].type << "   | " << setw(9) << details[i].amou << " | " << setw(20) << fixed << setprecision(1) << details[i].wgh << " |\n";
    }

    cout << "-------------------------------------------------------\n";
    cout << "|   Note: O - original, P - purchased, Z - borrowed   |\n";
    cout << "-------------------------------------------------------\n";
}

int lab_7() 
{
    int n;
    cout << "Vvedit` kil`kist detaley: ";
    cin >> n;
    Detail* details = new Detail[n];

    input(details, n);
    sort(details, n);
    output(details, n);

    delete[] details;

    return 0;
}