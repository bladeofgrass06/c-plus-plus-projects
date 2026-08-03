#include <iostream>
#include <iomanip>

using namespace std;

float startTemperature = 0, endTemperature = 0, increment = 0;

void setValues() {
	cout << endl << "Enter a starting temperature in degrees Celcius: ";
	cin >> startTemperature;
	cout << "Enter an ending temperature in degrees Celcius: ";
	cin >> endTemperature;
	cout << "Enter the increment between temperatures in degrees Celsius: ";
	cin >> increment;
}

void printTempsAndIncrement() {   
    cout << left << fixed << setprecision(2) << setw(15) << startTemperature << setw(15) << (1.8 * startTemperature) + 32 << setw(15) 
         << startTemperature + 273.15 << endl;
    startTemperature += increment;
}

int main() {
	setValues();

    cout << endl << "WHILE LOOP" << endl << endl << left << setw(15) << "CELCIUS" << setw(15) << "FAHRENHEIT" << setw(15) << "KELVIN" 
         << endl << endl;

    if (increment > 0)       while (startTemperature <= endTemperature) printTempsAndIncrement();
    else if (increment < 0)  while (startTemperature >= endTemperature) printTempsAndIncrement();
    else {
        printTempsAndIncrement();
        cout << endl << "Increment is 0. Nothing changes." << endl;
    }
	
    setValues();

    cout << endl << "DO-WHILE LOOP" << endl << endl << left << setw(15) << "CELCIUS" << setw(15) << "FAHRENHEIT" << setw(15) << "KELVIN" 
         << endl << endl;

    if (increment > 0)       do printTempsAndIncrement(); while (startTemperature <= endTemperature);
    else if (increment < 0)  do printTempsAndIncrement(); while (startTemperature >= endTemperature);
    else {
        printTempsAndIncrement();
        cout << endl << "Increment is 0. Nothing changes." << endl;
    }
	
    setValues();

    cout << endl << "FOR LOOP" << endl << endl << left << setw(15) << "CELCIUS" << setw(15) << "FAHRENHEIT" << setw(15) << "KELVIN" 
         << endl << endl;

    if (increment > 0) 
        for (float sT = startTemperature; sT <= endTemperature; sT += increment) 
            cout << left << fixed << setprecision(2) << setw(15) << sT << setw(15) << (1.8 * sT) + 32 << setw(15) << sT + 273.15 << endl;
    else if (increment < 0) 
        for (float sT = startTemperature; sT >= endTemperature; sT += increment) 
            cout << left << fixed << setprecision(2) << setw(15) << sT << setw(15) << (1.8 * sT) + 32 << setw(15) << sT + 273.15 << endl;
    else {
        printTempsAndIncrement();
        cout << endl << "Increment is 0. Nothing changes." << endl;
    }

    cout << endl;
	return 0;
}