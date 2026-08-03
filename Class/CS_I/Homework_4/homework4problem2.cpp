#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	string binary = "";

    bool isValid = false;
    while (!isValid) {
        cout << endl << "Enter a binary number: ";
        getline(cin, binary);

        for (const char& c : binary) {
            if ((c != '0') && (c != '1')) {
                cerr << "Error: Invalid binary number!" << endl;
                isValid = false;
                break;
            } 
            isValid = true;
        }
    }

    int decimal = 0;
    for (int i = 0; i < binary.length(); i++)
        decimal += ((binary.at(i) - 48) * pow(2, binary.length() - 1 - i));

    cout << endl << binary << " converted to decimal is " << decimal << endl << endl;
	return 0;
}