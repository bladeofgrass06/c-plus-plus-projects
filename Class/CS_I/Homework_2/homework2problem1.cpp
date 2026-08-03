#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	ifstream temps("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I//Homework_2/temps.txt");
    ofstream table("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_2/table.txt");	
	if (!temps || !table) {
		if (!temps) cerr << endl << "Error: 'temps.txt' not found!" << endl << endl;
		if (!table) cerr << endl << "Error: 'table.txt' not found!" << endl << endl;
		temps.close();
    	table.close();
		return 0;
	}
	
    table << left << setw(15) << "Celsius" << setw(15) << "Fahrenheit" << setw(15) << "Kelvin" << endl;

	float temp = 0;
	while (temps >> temp)
		table << fixed << setprecision(2) << left << setw(15) 
			  << temp << setw(15) << (1.8 * temp) + 32 << setw(15) << temp + 273.15 << endl;

	temps.close();
    table.close();
	return 0;
}