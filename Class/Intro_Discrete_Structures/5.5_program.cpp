/*********************************************************************
*   CS 214-01 Section 5.5 Programming Assignment
*   File: 5.5_program.cpp
*   Author: Noah Borden
*   Desc: This program accepts input from a user including the time 
          to complete one operation and the minimum, median, and
          maximum amount of iterations. The program then calculates
          the amount of time that the three provided iterations take
          to complete using worst-case time complexities. The program
          then compiles all the calculated times in a table.
*   Date: Wednesday, October 29
*
*   I attest that this program is entirely my own work
*********************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

long double factorial(unsigned int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
};

string convertTime(double time) {
    if (time < 60) return to_string(time) + " seconds";
    time /= 60;
    if (time < 60) return to_string(time) + " minutes";
    time /= 60;
    if (time < 24) return to_string(time) + " hours";
    time /= 24;
    if (time < 365) return to_string(time) + " days";
    time /= 365;
    if (time < 100) return to_string(time) + " years";
    time /= 100;
    if (time <= 1000) return to_string(time) + " centuries";
    return "Greater than 1000 centuries";
};

int main() {
    float timePerIteration = 0;
    cout << endl << "Insert the time it takes to complete one iteration (in seconds): ";
    cin >> timePerIteration;

    unsigned int minimumIterations = 0, medianIterations = 0, maximumIterations = 0;
    cout << "Insert the minimum amount of iterations: ";
    cin >> minimumIterations;

    cout << "Insert the median amount of iterations: ";
    cin >> medianIterations;

    cout << "Insert the maximum amount of iterations: ";
    cin >> maximumIterations;

    string minimumLog2 = convertTime(log2(minimumIterations) * timePerIteration),
           medianLog2 = convertTime(log2(medianIterations) * timePerIteration),
           maximumLog2 = convertTime(log2(maximumIterations) * timePerIteration),

           minimumN = convertTime(minimumIterations * timePerIteration),
           medianN = convertTime(medianIterations * timePerIteration),
           maximumN = convertTime(maximumIterations * timePerIteration),

           minimumNlog2 = convertTime(minimumIterations * log2(minimumIterations) * timePerIteration),
           medianNlog2 = convertTime(medianIterations * log2(medianIterations) * timePerIteration),
           maximumNlog2 = convertTime(maximumIterations * log2(maximumIterations) * timePerIteration),

           minimumSquared = convertTime(pow(minimumIterations, 2) * timePerIteration),
           medianSquared = convertTime(pow(medianIterations, 2) * timePerIteration),
           maximumSquared = convertTime(pow(maximumIterations, 2) * timePerIteration),

           minimumCubed = convertTime(pow(minimumIterations, 3) * timePerIteration),
           medianCubed = convertTime(pow(medianIterations, 3) * timePerIteration),
           maximumCubed = convertTime(pow(maximumIterations, 3) * timePerIteration),

           minimumFactorial = convertTime(factorial(minimumIterations) * timePerIteration),
           medianFactorial = convertTime(factorial(medianIterations) * timePerIteration),
           maximumFactorial = convertTime(factorial(maximumIterations) * timePerIteration),

           minimum2PowN = convertTime(pow(2, minimumIterations) * timePerIteration),
           median2PowN = convertTime(pow(2, medianIterations) * timePerIteration),
           maximum2PowN = convertTime(pow(2, maximumIterations) * timePerIteration);

    cout << endl << left << setw(15) << "Order" << setw(30) 
         << to_string(minimumIterations) + " iterations" << setw(30) 
         << to_string(medianIterations) + " iterations" << to_string(maximumIterations) + " iterations" 
         << endl << setfill('-') << setw(105) << '-' << setfill(' ') << endl
         << setw(15) << "log_2 (n)"     << setw(30) << minimumLog2    << setw(30) << medianLog2    
         << maximumLog2    << endl
         << setw(15) << "n"             << setw(30) << minimumN      << setw(30) << medianN      
         << maximumN      << endl
         << setw(15) << "n * log_2 (n)" << setw(30) << minimumNlog2   << setw(30) << medianNlog2   
         << maximumNlog2   << endl
         << setw(15) << "n^2"           << setw(30) << minimumSquared << setw(30) << medianSquared 
         << maximumSquared << endl
         << setw(15) << "n^3"           << setw(30) << minimumCubed   << setw(30) << medianCubed   
         << maximumCubed   << endl
         << setw(15) << "n!"            << setw(30) << minimumFactorial << setw(30) << medianFactorial 
         << maximumFactorial << endl
         << setw(15) << "2^n"           << setw(30) << minimum2PowN  << setw(30) << median2PowN  
         << maximum2PowN  << endl << endl;

    return 0;
}