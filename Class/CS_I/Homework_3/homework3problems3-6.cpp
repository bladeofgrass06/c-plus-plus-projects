#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <cstdio>
#include <sstream>

using namespace std;

ifstream file("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_3/reduced_column.txt");

string removeWhitespace(const string &string) {
    size_t start = string.find_first_not_of(" \t\n\r");
    size_t end = string.find_last_not_of(" \t\n\r");
    return string.substr(start, end - start + 1); 
}

string printStations(vector<string> v) {
    if (v.size() == 1)       return v[0];
    else if (v.size() == 2)  return v[0] + " and " + v[1];
    else {
        string sentence = "";
        for (string s : v)
            if (s != v.back())  sentence += s + ", ";
            else                sentence += "and " + s;
        return sentence;
    }
}
void problemThree() {
    if (!file) {
        cerr << endl << "Error: 'reduced_column.txt' not found!" << endl << endl;
        file.close();
        return;
    }

    string line = "", highestStation = "", lowestStation = "";

    getline(file, line);
    getline(file, line);

    vector<string> highestStations = {}, lowestStations = {};

    float maxTMAX = stof(line.substr(97, 8)), minTMIN = stof(line.substr(105, 8));

    while (getline(file, line)) { 
        float currentTMAX = stof(line.substr(97, 8)), currentTMIN = stof(line.substr(105, 8));
        string stationName = removeWhitespace(line.substr(0, 50));

        if (currentTMAX > maxTMAX) { 
            maxTMAX = currentTMAX; 
            highestStations.clear(); 
            highestStations.push_back(stationName);
        } else if (currentTMAX == maxTMAX)
            highestStations.push_back(stationName);

        if (currentTMIN < minTMIN) { 
            minTMIN = currentTMIN; 
            lowestStations.clear(); 
            lowestStations.push_back(stationName);
        } else if (currentTMIN == minTMIN)
            lowestStations.push_back(stationName);
    }

    printf("\n%s recorded a high of %.2f°F.\n", printStations(highestStations).c_str(), maxTMAX);
    printf("%s recorded a low of %.2f°F.\n\n", printStations(lowestStations).c_str(), minTMIN);
    file.close();
}

void problemFour() {
    if (!file) {
        cerr << endl << "Error: 'reduced_column.txt' not found!" << endl << endl;
        file.close();
        return;
    }

    unsigned int userDay = 0;
    bool isValid = false;
    while (!isValid) {
        cout << endl << "Enter a day of the month (1-31): ";
        cin >> userDay;

        if ((userDay < 1) || (userDay > 31))  cerr << "Error: Invalid day!";
        else                                  isValid = true;
    }

    string line = "";
    double sum = 0;

    getline(file, line);
    while(getline(file, line)) {
        unsigned int fileDay = stoi(line.substr(82, 2));
        float prcp = stod(line.substr(89, 5));
        if (userDay == fileDay) sum += prcp;
    }

    printf("\nThe total precipitation on 12/%i/2023 was %.2f inches.\n\n", userDay, sum);
    file.close();
}

bool isStationFound(ifstream& file, string station) {
    string line = "";
    while (getline(file, line))
        if (removeWhitespace(line.substr(0, 50)) == station) {
            file.clear();
            file.seekg(0, ios::beg);
            return true;
        }
    file.clear();
    file.seekg(0, ios::beg);
    return false;
}
void problemFive() {
    if (!file) {
        cerr << endl << "Error: 'reduced_column.txt' not found!" << endl << endl;
        file.close();
        return;
    }

    string userStation = "";
    unsigned int userDay = 0;
    bool isValid = false;
    while (!isValid) {
        cin.ignore();
        cout << endl << "Enter a station name (ALL CAPS): ";
        getline(cin, userStation);
        cout << "Enter a day of the month (1-31): ";
        cin >> userDay;

        bool stationFound = isStationFound(file, userStation);
        if (!stationFound || ((userDay < 1) || (userDay > 31))) {
            if (!stationFound)                    cerr << "Error: Station not found!" << endl;
            if ((userDay < 1) || (userDay > 31))  cerr << "Error: Invalid day!" << endl;
        } else                                    isValid = true;
    }

    string line = "";
    getline(file, line);
    while(getline(file, line)) {
        if ((userStation == removeWhitespace(line.substr(0, 50))) && 
            (userDay == stoi(line.substr(82, 2)))) {
            printf("\nFor %s on 12/%i/2023, the total precipitation was %.2f inches, with a high of %.2f°F and a low of %.2f°F\n\n", 
                userStation.c_str(), userDay, stof(line.substr(89, 8)), stof(line.substr(97, 8)), 
                stof(line.substr(105, 8)));
            file.close();
            return;
        }
    }
}

void problemSix() {
    ofstream outFile("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_3/homework3problem6.txt");
    if (!file || !outFile) {
        cout << endl;
        if (!file)     cerr << "Error: 'reduced_column.txt' not found!" << endl;
        if (!outFile)  cerr << "Error: 'homework3problem6.txt' not found!" << endl;
        cout << endl;
        file.close();
        outFile.close();
        return;
    }

    string line = "";

    float NL = 0, SL = 0, WL = 0, EL = 0;
    unsigned int userDay = 0;
    bool isValid = false;
    while (!isValid) {
        cout << endl << "Enter latitudinal (-90 to 90) and longitudinal (-180 to 180) values using the following format: 'northern_latitude southern_latitude western_longitude eastern_longitude'." << endl << endl << "> "; 
        cin >> NL >> SL >> WL >> EL;
        cout << endl << "ENTER THE DAY OF THE MONTH (1-30): ";
        cin >> userDay;

        bool validNL = (NL >= -90) && (NL <= 90), validSL = (SL >= -90) && (SL <= 90), validWL = (WL >= -180) && (WL <= 180), 
             validEL = (EL >= -180) && (EL <= 180), validDay = (userDay >= 1) && (userDay <= 31);
        
        if (!validNL || !validSL || !validWL || !validEL || !validDay) {
            if (!validNL)   cerr << "Error: Invalid northern latitude!" << endl;
            if (!validSL)   cerr << "Error: Invalid southern latitude!" << endl;
            if (!validWL)   cerr << "Error: Invalid western latitude!" << endl;
            if (!validEL)   cerr << "Error: Invalid eastern latitude!" << endl;
            if (!validDay)  cerr << "Error: Invalid day!" << endl;
        } else              isValid = true;
    }

    getline(file, line);
    outFile << line << endl;

    while(getline(file, line))
        if (((stof(line.substr(60, 10)) <= NL) && (stof(line.substr(60, 10)) >= SL)) && ((stof(line.substr(70, 10)) <= EL) && 
            (stof(line.substr(70, 10)) >= WL)) && ((stoi(line.substr(82, 2)) == userDay)))
                outFile << line << endl;

    cout << endl << "Output file 'homework3problem6.txt' successfully created!" << endl << endl;
    file.close();
    outFile.close();
}

int main() {
	cout << endl << "WELCOME TO THE SUPER-DUPER DECEMBER 2023 WEATHER GIZMO!" << endl
         << "SELECT ONE OF THE FOLLOWING PROGRAMS BY TYPING IN ITS RESPECTIVE NUMBER:" << endl
         << "    1. Find Highest/Lowest Temperature" << endl
         << "    2. Find Total Precipitation for a Day" << endl
         << "    3. Find PRCP, TMAX, TMIN for a Station for a Day" << endl
         << "    4. Find All Stations Within Given Coordinates" << endl << endl << "> ";

    unsigned int userNum = 0;
    bool isValid = false;
    while (!isValid) {
        cin >> userNum;
        if ((userNum < 1) || (userNum > 4)) {
            cerr << "ERROR: Invalid number!" << endl;
            cout << "> ";
        } else isValid = true;
    }

    switch (userNum) {
        case 1:
            problemThree();
            break;
        case 2:
            problemFour();
            break;
        case 3:
            problemFive();
            break;
        case 4:
            problemSix();
            break;
    }
	return 0;
}