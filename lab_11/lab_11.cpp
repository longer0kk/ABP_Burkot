#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string name;
    int year;
    string color;

public:
    Car() : name("Unknown"), year(0), color("Unknown") {}

    Car(string name, int year, string color) : name(name), year(year), color(color) {}

    Car(const Car &car) : name(car.name), year(car.year), color(car.color) {}

    ~Car() {}

    void setYear(int y) {
        year = y;
    }

    void setName(string n) {
        name = n;
    }

    void setColor(string c) {
        color = c;
    }

    void showAllData() const {
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "Color: " << color << endl;
    }
};

class SoldCar : public Car {
private:
    string buyerName;

public:
    SoldCar() : Car(), buyerName("Unknown") {}

    SoldCar(string name, int year, string color, string buyerName)
        : Car(name, year, color), buyerName(buyerName) {}

    SoldCar(const SoldCar &soldCar) : Car(soldCar), buyerName(soldCar.buyerName) {}

    ~SoldCar() {}

    void setBuyerName(string name) {
        buyerName = name;
    }

    void showAllData() const {
        Car::showAllData();
        cout << "Buyer name: " << buyerName << endl;
    }
};

int lab_11() {
    string mark, color, markk, colorr, buyern;
    int year, yearr, choice;

    Car car;
    cout << "\nEnter information for a car in stock (Mark, year, color):\n";
    cin >> mark >> year >> color;
    car.setName(mark);
    car.setYear(year);
    car.setColor(color);

    SoldCar soldCar;
    cout << "\nEnter information about sold car (Mark, year, color, buyer name):\n";
    cin >> markk >> yearr >> colorr >> buyern;
    soldCar.setName(markk);
    soldCar.setYear(yearr);
    soldCar.setColor(colorr);
    soldCar.setBuyerName(buyern);

    do {
        cout << "\nWhat do you want to do now?\n";
        cout << "1. Change information about car in stock\n";
        cout << "2. Change information about sold car\n";
        cout << "3. Show all information\n";
        cout << "4. Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                int choice1;
                cout << "\nWhat exactly?\n";
                cout << "1. Change name\n";
                cout << "2. Change year\n";
                cout << "3. Change color\n";
                cin >> choice1;
                switch (choice1)
                {
                    case 1:
                        cout << "Enter new name: ";
                        cin >> mark;
                        car.setName(mark);
                        break;

                    case 2:
                        cout << "Enter new year: ";
                        cin >> year;
                        car.setYear(year);
                        break;

                    case 3:
                        cout << "Enter new color: ";
                        cin >> color;
                        car.setColor(color);
                        break;

                    default:
                        cout << "Wrong option\n";
                        break;
                }
                break;

            case 2:
                int choice2;
                cout << "\nWhat exactly?\n";
                cout << "1. Change name\n";
                cout << "2. Change year\n";
                cout << "3. Change color\n";
                cout << "4. Change buyer's name\n";
                cin >> choice2;
                switch (choice2)
                {
                    case 1:
                        cout << "Enter new name: ";
                        cin >> markk;
                        soldCar.setName(markk);
                        break;

                    case 2:
                        cout << "Enter new year: ";
                        cin >> yearr;
                        soldCar.setYear(yearr);
                        break;

                    case 3:
                        cout << "Enter new color: ";
                        cin >> colorr;
                        soldCar.setColor(colorr);
                        break;

                    case 4:
                        cout << "Enter new buyer's name: ";
                        cin >> buyern;
                        soldCar.setBuyerName(buyern);
                        break;

                    default:
                        cout << "Wrong option\n";
                        break;
                }
                break;

            case 3:
                cout << "\nInformation on car in stock:\n";
                car.showAllData();
                cout << "\nInformation on sold car:\n";
                soldCar.showAllData();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Wrong option\n";
                break;
        }

    } while (choice != 4);

    return 0;
}