#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Station {
    string id = "", lat = "", lon = "", alt = "", mon = "", day = "", year = "", 
           hour = "", min = "", sec = "", temp = "", prcp = "", wind = "", press = "";
};

void print(Station s) {
    cout << left << setw(11) << s.id << setw(11) << s.lat << setw(16) << s.lon << setw(8) << s.alt << setw(2) << s.mon << setw(3) 
         << s.day << setw(5) << s.year << setw(3) << s.hour << setw(3) << s.min << setw(5) << s.sec << setw(9) << s.temp << setw(8) 
         << s.prcp << setw(7) << s.wind << s.press << endl;
}

int main() {
    ifstream file("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_6/portable_weather_station_data.txt");
    if (!file) {
        cerr << endl << "Error: 'portable_weather_station_data.txt' not found!" << endl << endl;
        file.close();
        return 0;
    }

    string id = "", day = "", line = "", legend = "";
    
    Station station[1000] = {};
    getline(file, legend);

    for (int i = 0; i < 1000; i++) {
        getline(file, line);
        file >> station[i].id >> station[i].lat >> station[i].lon >> station[i].alt >> station[i].mon   
             >> station[i].day >> station[i].year >> station[i].hour >> station[i].min 
             >> station[i].sec >> station[i].temp >> station[i].prcp >> station[i].wind 
             >> station[i].press;
    }

    cout << endl << "Enter an ID and a day to view matching records: ";
    cin >> id >> day;

    cout << endl << legend << endl;

    for (int i = 0; i < 1000; i++)
        if (id == station[i].id && day == station[i].day)
            print(station[i]);

    cout << endl << "Enter a day to view records with at least 1.0 inches of precipitation: ";
    cin >> day;

    cout << endl << legend << endl;

    for (int i = 0; i < 1000; i++)
        if (day == station[i].day && stof(station[i].prcp) >= 1)
            print(station[i]);

    cout << endl;
    file.close();
    return 0;
}