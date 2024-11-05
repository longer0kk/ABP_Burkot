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

void clear_file() 
{
    ofstream f("file.txt", ios::trunc);
    if (!f.is_open()) {
        perror("Pomilka vidkritya failu dlya ochishchenya");
    }
    f.close();
}

void f_add(Detal4ik* work) 
{
    ofstream f("file.txt", ios::app);
    if (!f.is_open()) 
    {
        perror("Pomilka vidkritya failu dlya dopisuvanya");
        return;
    }

    f << work->name << " "
      << work->type << " "
      << work->amou << " "
      << work->wgh << endl;
    f.close();
}

void fshow_all() 
{
    ifstream f("file.txt");
    if (!f.is_open()) 
    {
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

void fdel_item(int record_num)
{
    ifstream f("file.txt");
    ofstream temp("temp.txt");
    if (!f.is_open() || !temp.is_open()) 
    {
        perror("Pomilka vidkritya failu dlya vidalennya");
        return;
    }

    Detal4ik det;
    int current_record = 1;
    while (f >> det.name >> det.type >> det.amou >> det.wgh) 
    {
        if (current_record != record_num) 
        {
            temp << det.name << " "
                 << det.type << " "
                 << det.amou << " "
                 << det.wgh << endl;
        }
        current_record++;
    }

    f.close();
    temp.close();
    remove("file.txt");
    rename("temp.txt", "file.txt");
}

int fcheck_number(int record_num)
{
    ifstream f("file.txt");
    if (!f.is_open()) 
    {
        perror("Pomilka vidkritya failu");
        return -1;
    }

    Detal4ik det;
    int current_record = 1;
    while (f >> det.name >> det.type >> det.amou >> det.wgh) 
    {
        if (current_record == record_num) 
        {
            f.close();
            return 0;
        }
        current_record++;
    }

    f.close();
    return -1;
}

void fshow_1(int record_num) 
{
    ifstream f("file.txt");
    if (!f.is_open()) 
    {
        perror("Pomilka vidkritya failu");
        return;
    }

    Detal4ik det;
    int current_record = 1;
    while (f >> det.name >> det.type >> det.amou >> det.wgh) 
    {
        if (current_record == record_num) 
        {
            cout << "Zapis " << record_num << ":\n";
            cout << "|    Name   | Type |  Amount   |  Weight per item (g) |\n";
            cout << "|-----------|------|-----------|----------------------|\n";
            cout << "|" << setw(10) << det.name << " |  " << det.type << "   | " << setw(9) << det.amou << " | " << setw(20) << fixed << setprecision(1) << det.wgh << " |\n";
            f.close();
            return;
        }
        current_record++;
    }

    cout << "Zapis z nomerom " << record_num << " ne znaideno.\n";
    f.close();
}

void menu()
{
    int choice, record_num;
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Pokazat` vsi zapisi\n";
        cout << "2. Vidalit` zapis\n";
        cout << "3. Perevirit` zapis za nomerom\n";
        cout << "4. Porazat` zapis za nomerom\n";
        cout << "5. Exit\n";
        cout << "Vash choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                fshow_all();
                break;
            case 2:
                cout << "Vvedit` nomer zapisu dlya vidalenya: ";
                cin >> record_num;
                fdel_item(record_num);
                cout << "Zapis vidaleno.\n";
                break;
            case 3:
                cout << "Vvedit` nomer zapisu dlya perevirki: ";
                cin >> record_num;
                if (fcheck_number(record_num) == 0)
                    cout << "Zapis z nomerom " << record_num << " znaideno.\n";
                else
                    cout << "Zapis z nomerom " << record_num << " ne znaideno.\n";
                break;
            case 4:
                cout << "Vvedit` nomer zapisu dlya pokazu: ";
                cin >> record_num;
                fshow_1(record_num);
                break;
            case 5:
                return;
            default:
                cout << "Wrong choice, try again.\n";
        }
    }
}

int lab_9()
{
    clear_file();
    const int max = 9;
    Detal4ik deta[max];
    int i = 0;

    while (i < max) 
    {
        cout << i + 1 << ". Enter: name, type, amount, weight of detail > " << endl;
        cin >> deta[i].name;

        if (strcmp(deta[i].name, "***") == 0) 
        {
            break;
        }

        cin >> deta[i].type >> deta[i].amou >> deta[i].wgh;
        f_add(&deta[i]);
        i++;
    }

    menu();
    return 0;
}