#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Detal4ik 
{
    char name[12];
    char type;
    unsigned short amou;
    float wgh;
};


void f_add(Detal4ik* work) {
    ofstream f("file.txt", ios::app);
    if (!f.is_open()) {
        perror("Pomilka vidkritya failu  dlya dopisuvanya");
        return;
    }

    f << work->name << " "
      << work->type << " "
      << work->amou << " "
      << work->wgh << endl;
    f.close();
}


void fshow_all() {
    ifstream f("file.txt");
    if (!f.is_open()) {
        perror("Pomilka vidkritya failu");
        return;
    }


    cout << "-------------------------------------------------------\n";
    cout << "|                Details information                  |\n";
    cout << "|-----------------------------------------------------|\n";
    cout << "|    Name   | Type |  Amount   |  Weight per item (g) |\n";
    cout << "|-----------|------|-----------|----------------------|\n";

    Detal4ik det;
    while (f >> det.name >> det.type >> det.amou >> det.wgh) 
    {
        cout << "|" << setw(10) << det.name << " |  " << det.type << "   | " << setw(9) << det.amou << " | " << setw(20) << fixed << setprecision(1) << det.wgh << " |\n";

    }

    cout << "-------------------------------------------------------\n";
    cout << "|   Note: O - original, P - purchased, Z - borrowed   |\n";
    cout << "-------------------------------------------------------\n";

    f.close();
}

int lab_9()
{
    const int max = 9;
    Detal4ik deta[max];
    int i = 0;


    while (i < max) {
        cout << i + 1 << ". Enter: name, type, amount, weight of detail > " << endl;
        cin >> deta[i].name;

        if (strcmp(deta[i].name, "***") == 0) {
            break;
        }

        cin >> deta[i].type >> deta[i].amou >> deta[i].wgh;

        f_add(&deta[i]);

        i++;
    }


    fshow_all();
}