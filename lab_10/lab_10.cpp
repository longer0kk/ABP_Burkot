#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Deta
{
public:
    char name[12];
    char type;
    unsigned short amou;
    float wgh;


    void set(const char* n, char t, unsigned short a, float w) {
        strncpy(name, n, 11);
        type = t;
        amou = a;
        wgh = w;
    }   

    void get(char * n, char &t, unsigned int &a, float &w)
    {
        delete[] n;
        n = new char [strlen(name)+1];
        strcpy(n, name);
        t = type;
        a = amou;
        w = wgh;
    }

    void show() const 
    {
    cout << "|" << setw(10) << name << " |  " << type << "   | " << setw(9) << amou << " | " << setw(20) << fixed << setprecision(1) << wgh << " |\n";
    }
};

void header() 
{
    cout << "-------------------------------------------------------\n";
    cout << "|                Details information                  |\n";
    cout << "|-----------------------------------------------------|\n";
    cout << "|    Name   | Type |  Amount   |  Weight per item (g) |\n";
    cout << "|-----------|------|-----------|----------------------|\n";
}

void footer() 
{
    cout << "-------------------------------------------------------\n";
    cout << "|   Note: O - original, P - purchased, Z - borrowed   |\n";
    cout << "-------------------------------------------------------\n";
}

int lab_10() {
    const int max = 9;
    Deta deta[max];
    int i = 0;

    while (i < max) {
        char name[12];
        char type;
        unsigned short amount;
        float weight;

        cout << i + 1 << ". Enter: name, type, amount, weight of detail > " << endl;
        cin >> setw(11) >> name;

        if (strcmp(name, "***") == 0) {
            break;
        }

        cin >> type >> amount >> weight;

        deta[i].set(name, type, amount, weight);
        i++;
    }

    header();
    for (int j = 0; j < i; ++j) {
        deta[j].show();
    }
    footer();

    return 0;
}