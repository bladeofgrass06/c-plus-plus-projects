#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // exp(1) returns Euler's number to the first power (2.71828...)
    double euler = exp(1), avogadro = 6.022e+23, mile = 5278;

    cout << endl << setw(42) << setfill('-') << '-' << endl;
    cout << setfill(' ') << "EULER" << setw(26) << "AVOGADRO" << setw(11) << "MILE" << endl;
    cout << setw(42) << setfill('-') << '-' << endl;
    for (int n = 1; n <= 14; n++) {
        cout << left << setfill('.') << setw(22) << fixed      << setprecision(n) << euler    << '.'
                     << setfill('.') << setw(14) << scientific << setprecision(3) << avogadro << '.'
                                                 << fixed      << setprecision(0) << mile     << endl;
    }
    cout << setw(42) << setfill('-') << '-' << endl << endl;

    return 0;
}