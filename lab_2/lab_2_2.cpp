// Variant 4

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int lab_2_2() {
    double sum = 0, term;
    const double EPS = 0.000001;
    int n;

    for (n = 0;; n++) {
        term = pow(-1, n) * ((pow(n, 2) + 1) / (pow(n, 3) + 3));

        if (fabs(term) >= EPS) 
        {
            sum += term;
        } else {
            break;
        }

        if (n == 9) {
            cout << "Suma 10 chleniv " << fixed << setprecision(6) << sum << endl;
        }
    }

    cout << "Full suma: " << fixed << setprecision(6) << sum << endl;
    return 0;
}