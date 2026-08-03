#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	unsigned int entry = 0;
    bool isValid = false;
    while (!isValid) {
        cout << endl << "Enter a directory entry number (>0): ";
        cin >> entry;
        if (entry < 1)  cerr << "Error: Invalid entry!" << endl;
        else            isValid = true;
    }

    unsigned int pg =   ((entry - 1) / 180) + 1;
    unsigned int col =  (((entry - 1) % 180) / 60) + 1;
    unsigned int ln =   ((entry - 1) % 60) + 1;

    printf("\nEntry number %i is located on page %i, column %i, and line %i.\n\n", 
        entry, pg, col, ln);
	return 0;
}