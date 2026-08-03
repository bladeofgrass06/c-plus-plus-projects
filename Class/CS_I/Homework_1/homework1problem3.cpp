#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

fstream file("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_1/holidays.txt");

void findHolidayOnMonthAndDay(int month, int day) {
    string line = "";
    while (getline(file, line)) {
        stringstream ss(line);
        unsigned int fileMonth = 0, fileDay = 0;
        char slash = ' ';
        string holiday = "";
        ss >> fileMonth >> slash >> fileDay;
        getline(ss, holiday);
        if ((month == fileMonth) && (day == fileDay)) {
            cout << endl << "Today is" << holiday << "." << endl << endl;
            file.close();
            return;
        }
    }
    cout << endl << "There is no holiday today." << endl << endl;
    file.close();
}

int main() {
    if (!file) {
        cerr << endl << "Error: 'holidays.txt' not found!" << endl << endl;
        file.close();
        return 0;
    }
    
    unsigned int userMonth = 0, userDay = 0;
    while (true) {
	    cout << endl << "Enter the current month: ";
	    cin >> userMonth;
	    cout << "Enter the current day: ";
	    cin >> userDay;

        switch (userMonth) {
            case 1:
                if (userDay > 31) { 
                    cerr << "Error: Invalid day!" << endl;
                    break;
                }
                findHolidayOnMonthAndDay(1, userDay);
                return 0;
            case 2:
                if (userDay > 29) { 
                    cerr << "Error: Invalid day!" << endl;
                    break;
                }
                findHolidayOnMonthAndDay(2, userDay);
                return 0;
            case 3:
                if (userDay > 31) { 
                    cerr << "Error: Invalid day!" << endl;
                    break;
                }
                findHolidayOnMonthAndDay(3, userDay);
                return 0;
            case 4:
                if (userDay > 30) { 
                    cerr << "Error: Invalid day!" << endl;
                    break;
                }
                findHolidayOnMonthAndDay(4, userDay);
                return 0;
            case 5:
                if (userDay > 31) { 
                    cerr << "Error: Invalid day!" << endl;
                    break;
                }
                findHolidayOnMonthAndDay(5, userDay);
                return 0;
            case 6:
                if (userDay > 30) { 
                    cerr << "Error: Invalid day!" << endl;
                    break;
                }
                findHolidayOnMonthAndDay(6, userDay);
                return 0;
            case 7:
                if (userDay > 31) { 
                    cerr << "Error: Invalid day!" << endl;
                    break;
                }
                findHolidayOnMonthAndDay(7, userDay);
                return 0;
            case 8:
                if (userDay > 31) { 
                    cerr << "Error: Invalid day!" << endl;
                    break;
                }
                findHolidayOnMonthAndDay(8, userDay);
                return 0;
            case 9:
                if (userDay > 30) { 
                    cerr << "Error: Invalid day!" << endl;
                    break;
                }
                findHolidayOnMonthAndDay(9, userDay);
                return 0;
            case 10:
                if (userDay > 31) { 
                    cerr << "Error: Invalid day!" << endl;
                    break;
                }
                findHolidayOnMonthAndDay(10, userDay);
                return 0;
            case 11:
                if (userDay > 30) { 
                    cerr << "Error: Invalid day!" << endl;
                    break;
                }
                findHolidayOnMonthAndDay(11, userDay);
                return 0;
            case 12:
                if (userDay > 31) { 
                    cerr << "Error: Invalid day!" << endl;
                    break;
                }
                findHolidayOnMonthAndDay(12, userDay);
                return 0;
            default:
                cerr << "Error: Invalid month or day!" << endl;
                break;
        }
    }
}