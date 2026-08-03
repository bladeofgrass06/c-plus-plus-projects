#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << endl << "WELCOME TO THE MONEY COUNTER!" << endl;

    cout << endl << "Counting bills..." << endl << endl;

    unsigned int hundreds = 0, hundredsTotal = 0, fifties = 0, fiftiesTotal = 0, twenties = 0, 
                 twentiesTotal = 0, tens = 0, tensTotal = 0, fives = 0, fivesTotal = 0, ones = 0, 
                 onesTotal = 0, dollars = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;
    float dollarsTotal = 0, quartersTotal = 0, dimesTotal = 0, nickelsTotal = 0, penniesTotal = 0, bills = 0, coins = 0;

    cout << "How many hundreds ($100) do you have? ";
    cin >> hundreds;
    hundredsTotal = hundreds * 10000;

    cin.ignore();
    cout << "How many fifties ($50) do you have? ";
    cin >> fifties;
    fiftiesTotal = fifties * 5000;

    cin.ignore();
    cout << "How many twenties ($20) do you have? ";
    cin >> twenties;
    twentiesTotal = twenties * 2000;

    cin.ignore();
    cout << "How many tens ($10) do you have? ";
    cin >> tens;
    tensTotal = tens * 1000;

    cin.ignore();
    cout << "How many fives ($5) do you have? ";
    cin >> fives;
    fivesTotal = fives * 500;

    cin.ignore();
    cout << "How many ones ($1) do you have? ";
    cin >> ones;
    onesTotal = ones * 100;

    bills += hundredsTotal + fiftiesTotal + twentiesTotal + tensTotal + fivesTotal + onesTotal;

    cout << endl << "Counting coins..." << endl << endl;

    cin.ignore();
    cout << "How many dollar coins ($1.00) do you have? ";
    cin >> dollars;
    dollarsTotal = dollars * 100;

    cin.ignore();
    cout << "How many quarters ($0.25) do you have? ";
    cin >> quarters;
    quartersTotal = quarters * 25;

    cin.ignore();
    cout << "How many dimes ($0.10) do you have? ";
    cin >> dimes;
    dimesTotal = dimes * 10;

    cin.ignore();
    cout << "How many nickels ($0.05) do you have? ";
    cin >> nickels;
    nickelsTotal = nickels * 5;

    cin.ignore();
    cout << "How many pennies ($0.01) do you have? ";
    cin >> pennies;
    penniesTotal = pennies;

    coins = dollarsTotal + quartersTotal + dimesTotal + nickelsTotal + penniesTotal;

    cout << endl << "Creating table..." << endl << endl;

    cout << "MONETARY INVENTORY" << endl;

    cout << right << fixed << setprecision(2);

    cout << setw(8) << endl << hundreds << " x $100 ($" << hundredsTotal / 100 << ")";
    cout << setw(8) << endl << fifties << " x $50 ($" << fiftiesTotal / 100 << ")";
    cout << setw(8) << endl << twenties << " x $20 ($" << twentiesTotal / 100 << ")";
    cout << setw(8) << endl << tens << " x $10 ($" << tensTotal / 100 << ")";
    cout << setw(8) << endl << fives << " x $5 ($" << fivesTotal / 100 << ")";
    cout << setw(8) << endl << ones << " x $1 ($" << onesTotal / 100 << ")" << endl;

    cout << setw(8) << endl << dollars << " x $1.00 ($" << dollarsTotal / 100 << ")";
    cout << setw(8) << endl << quarters << " x $0.25 ($" << quartersTotal / 100 << ")";
    cout << setw(8) << endl << dimes << " x $0.10 ($" << dimesTotal / 100 << ")";
    cout << setw(8) << endl << nickels << " x $0.05 ($" << nickelsTotal / 100 << ")";
    cout << setw(8) << endl << pennies << " x $0.01 ($" << penniesTotal / 100 << ")" << endl;

    cout << endl << "Bills total: $" << bills / 100;
    cout << endl << "Coins total: $" << coins / 100 << endl;

    cout << endl << "Grand total: $" << (bills + coins) / 100 << endl << endl;
}