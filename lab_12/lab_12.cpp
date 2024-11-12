#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Detal
{
private:
    
    char name[12];
    char type;
    unsigned short amou;
    float wgh;

public:
    
    Detal() : type(' '), amou(0), wgh(0.0f) 
    {
        strncpy(name, "", sizeof(name) - 1);
    }
    
    void set(const char* n, char t, unsigned short a, float w) {
        strncpy(name, n, 11);
        type = t;
        amou = a;
        wgh = w;
    }   

    void get(char * n, char &t, unsigned int &a, float &w)
    {
        strcpy(n, name);
        t = type;
        a = amou;
        w = wgh;
    }

    void show() const 
    {
    cout << "|" << setw(10) << name << " |  " << type << "   | " << setw(9) << amou << " | " << setw(20) << fixed << setprecision(1) << wgh << " |\n";
    }

    Detal& operator=(const Detal& other) {
        if (this != &other) {
            strncpy(name, other.name, sizeof(name) - 1);
            type = other.type;
            amou = other.amou;
            wgh = other.wgh;
        }
        return *this;
    }

    Detal operator+(const Detal& other) const {
        Detal result;
        strncpy(result.name, name, sizeof(result.name) - 1);
        strncat(result.name, other.name, sizeof(result.name) - strlen(result.name) - 1);
        result.type = type;
        result.amou = amou + other.amou;
        result.wgh = wgh + other.wgh;
        return result;
    }

    bool operator==(const Detal& other) const {
        return (strcmp(name, other.name) == 0) && (type == other.type) && (amou == other.amou) && (wgh == other.wgh);
    }

    friend istream& operator>>(istream& is, Detal& d) {
        is >> setw(11) >> d.name >> d.type >> d.amou >> d.wgh;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Detal& d) {
        os << "|" << setw(10) << d.name << " |  " << d.type << "   | " << setw(9) << d.amou << " | " << setw(20) << fixed << setprecision(1) << d.wgh << " |";
        return os;
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

int lab_12() 
{
    const int max = 9;
    Detal deta[max];
    int i = 0;

    while (i < max) 
    {
        char name[12];
        char type;
        unsigned short amount;
        float weight;

        cout << i + 1 << ". Enter: name, type, amount, weight of detail > " << endl;
        cin >> setw(11) >> name;

        if (strcmp(name, "***") == 0) 
        {
            break;
        }

        cin >> type >> amount >> weight;

        deta[i].set(name, type, amount, weight);
        i++;
    }

    header();
    for (int j = 0; j < i; ++j) {
        cout << deta[j] << endl;
    }
    footer();

    Detal copyDetal;
    copyDetal = deta[0];
    cout << "\nCopy of Detal 1:\n";
    header();
    cout << copyDetal << endl;
    footer();

    if (i >= 2) 
    {
        Detal sumDetal = deta[0] + deta[1];
        cout << "\nCombined Detal:\n";
        header();
        cout << sumDetal << endl;
        footer();
    
        if (deta[0] == deta[1]){
            cout << "Details are equal\n";
        } else {
            cout << "Details are not equal\n";
        }
    } else {
        cout << "Not enough details to perform addition or comparison.\n";
    }

    return 0;
}