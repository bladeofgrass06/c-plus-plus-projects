#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string removeWhitespace(const string &string) {
    size_t start = string.find_first_not_of(" \t\n\r");
    size_t end = string.find_last_not_of(" \t\n\r");
    return string.substr(start, end - start + 1); 
}

int main() {
    ifstream inputFile("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_3/AL_Weather_Stations_Dec_23.txt");
    ofstream filteredFile(
        "/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_3/Filtered_AL_Weather_Station.txt"),    
             reducedFile("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_3/reduced_column.txt");
    if (!inputFile || !filteredFile || !reducedFile) {
        cout << endl;
        if (!inputFile)     cout << "Error: 'AL_Weather_Stations_Dec_23.txt' not found!" << endl; 
        if (!filteredFile)  cout << "Error: 'Filtered_AL_Weather_Station.txt' not found!" << endl;
        if (!reducedFile)   cout << "Error: 'reduced_column.txt' not found!" << endl;
        cout << endl;
        inputFile.close();
        filteredFile.close();
        reducedFile.close();
        return 0;
    }

    string line = "";

    getline(inputFile, line);
    filteredFile << line << endl;
    reducedFile  << line.substr(18, 50) << line.substr(69, 10) << line.substr(80, 10) << line.substr(91, 10) 
                 << line.substr(102, 9) << line.substr(129, 8) << line.substr(165, 8) << line.substr(174, 8) << endl;

    getline(inputFile, line);
    filteredFile << line << endl;

    while (getline(inputFile, line)) {
        string date = line.substr(102, 9);
        float prcp = stof(line.substr(129, 8)), tmax = stof(line.substr(165, 8)), tmin = stof(line.substr(174, 8));
        if ((prcp != -9999) && (tmax != -9999) && (tmin != -9999)) {
            filteredFile << line << endl;
            reducedFile << left  << setw(50) << removeWhitespace(line.substr(18, 50)) 
                        << fixed << setw(10) << setprecision(2) << stof(line.substr(69, 10)) 
                                 << setw(10) << setprecision(4) << stof(line.substr(80, 10)) 
                                 << setw(10) << stof(line.substr(91, 10)) 
                                 << setw(8)  << date.substr(4, 2) + date.substr(6, 2) + date.substr(0, 4) << " " 
                                 << setw(8)  << setprecision(2) << prcp << setw(8) << tmax << setw(8) << tmin << endl;
        }
    }

    inputFile.close();
    filteredFile.close();
    reducedFile.close();
    return 0;
}