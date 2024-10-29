#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Details
{
    char name[12];
    char type;
    unsigned short amou;
    float wgh;
};

struct Det
{
    Details data;
    Det *next;
};

void push(Det** top, Details d);
void popAndDisplay(Det* top);

void push(Det** top, Details d)
{
    Det* newDet = new Det;
    newDet->data = d;
    newDet->next = *top;
    *top = newDet;
}

void popAndDisplay(Det* top)
{
    cout << "-------------------------------------------------------\n";
    cout << "|                Details information                  |\n";
    cout << "|-----------------------------------------------------|\n";
    cout << "|    Name   | Type |  Amount   |  Weight per item (g) |\n";
    cout << "|-----------|------|-----------|----------------------|\n";

    while (top) {
        cout << "|" << setw(10) << left << top->data.name
             << " |  " << top->data.type
             << "   | " << setw(9) << top->data.amou
             << " | " << setw(20) << fixed << setprecision(1) << top->data.wgh << " |\n";

        Det* temp = top;
        top = top->next;
        delete temp;
    }

    cout << "-------------------------------------------------------\n";
    cout << "|   Note: O - original, P - purchased, Z - borrowed   |\n";
    cout << "-------------------------------------------------------\n";
}

int lab_8()
{
    const int max = 10;
    Det* top = nullptr;
    Details in;
    int i = 0;

    while (i < max) {
        cout << i + 1 << ". Enter: name, type, amount, weight of detail > ";
        cin >> in.name;

        if (strcmp(in.name, "***") == 0) {
            break;
        }

        cin >> in.type >> in.amou >> in.wgh;
        push(&top, in);
        i++;
    }

    popAndDisplay(top);

    return 0;
}