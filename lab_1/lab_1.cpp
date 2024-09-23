#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    char name1[12], name2[12], name3[12];
    char type1, type2, type3;
    unsigned short amou1, amou2, amou3;
    float wgh1, wgh2, wgh3;

    cout << "1. Enter: name, type, amount, weight of 1 detail > ";
    cin >> name1 >> type1 >> amou1 >> wgh1;
    cout << "2. Enter: name, type, amount, weight of 1 detail > ";
    cin >> name2 >> type2 >> amou2 >> wgh2;
    cout << "3. Enter: name, type, amount, weight of 1 detail > ";
    cin >> name3 >> type3 >> amou3 >> wgh3;

    cout << "------------------------------------------------------\n";
    cout << "|               Details information                  |\n";
    cout << "|----------------------------------------------------|\n";
    cout << "|  Name  |  Type  | Amount |    Weight per item (g)  |\n";
    cout << "|--------|--------|--------|-------------------------|\n";

    cout << setw(12) << name1 << " |  " << type1 << "  | "
        << setw(9) << amou1 << " | " << setw(11) << fixed << setprecision(1) << wgh1 << " |\n";
    cout << setw(12) << name2 << " |  " << type2 << "  | "
        << setw(9) << amou2 << " | " << setw(11) << fixed << setprecision(1) << wgh2 << " |\n";
    cout << setw(12) << name3 << " |  " << type3 << "  | "
        << setw(9) << amou3 << " | " << setw(11) << fixed << setprecision(1) << wgh3 << " |\n";

    cout << "-------------------------------------------------------\n";
    cout << "|   Note: O - original, P - purchased, Z - borrowed   |\n";
    cout << "-------------------------------------------------------\n";

    return 0;
}