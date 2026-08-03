#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    fstream file("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_1/holidays.txt");
    if (!file) {
        cerr << endl << "Error: 'holidays.txt' not found!" << endl << endl;
        file.close();
        return 0;
    }
    
    unsigned int userMonth = 0, userDay = 0;
	cout << endl << "Enter the current month: ";
	cin >> userMonth;
	cout << "Enter the current day: ";
	cin >> userDay;

    while ((userMonth < 1) || ((userMonth == 2) && (userDay > 29)) || (((userMonth == 4) || 
           (userMonth == 6) || (userMonth == 9) || (userMonth == 11)) && (userDay > 30)) || (((userMonth == 1) || (userMonth == 3)  || 
           (userMonth == 5) || (userMonth == 7) || (userMonth == 8) || (userMonth == 10) || (userMonth == 12)) && (userDay > 31)) || 
           (userMonth > 12) || (userDay < 1) || (userDay > 31)) {
                cerr << "Error: Invalid month or day!" << endl << endl;
                cout << "Enter the current month: ";
	            cin >> userMonth;
	            cout << "Enter the current day: ";
	            cin >> userDay;
    }

    string line = "";
    while (getline(file, line)) {
        stringstream ss(line);
        int fileMonth = 0, fileDay = 0;
        char slash = ' ';
        string holiday = "";
        ss >> fileMonth >> slash >> fileDay;
        getline(ss, holiday);
        if ((userMonth == fileMonth) && (userDay == fileDay)) {
            cout << endl << "Today is" << holiday << "." << endl << endl;
            file.close();
            return 0;
        }
    }
    cout << endl << "There is no holiday today." << endl << endl;
    file.close();
	return 0;
}