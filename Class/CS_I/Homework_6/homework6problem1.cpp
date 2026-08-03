#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ifstream file
        ("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_6/dinner_reservations.txt");
    if (!file) {
        cerr << endl << "Error: 'dinner_reservations.txt' not found!" << endl << endl;
        file.close();
        return 0;
    }

    string date = "", line = "";

    cout << endl << "Enter a date in the form MM DD YYYY: ";
    getline(cin, date);

    getline(file, line);
    cout << endl << line << endl;
    while (getline(file, line)) if (date == line.substr(18, 9)) cout << line << endl;

    cout << endl;
    file.close();
    return 0;
}