// Variant 4

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int lab_2_2() {
    const double eps = 0.000001;
    double sum_10 = 0;
    double sum_full = 0;
    double term;
    int n = 0;

    for (n = 0; n < 10; n++) {
        term = pow(-1, n) * (pow(n, 2) + 1) / (pow(n, 3) + 3);
        sum_10 += term;
    }
    cout << "Suma pershih 10 chleniv: " << sum_10 << endl;
}