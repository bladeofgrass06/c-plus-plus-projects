#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

int main() {
	ifstream file("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_2/UAH_sample.txt");
    if (!file) {
        cout << endl << "Error: 'UAH_sample.txt' not found!" << endl << endl;
        file.close();
        return 0;
    }

    unsigned int letterCount[10] = {0}, alphaCount[26] = {0};

    string word = "";
    while (file >> word) {
        unsigned int wordLength = 0;
        for (int i = 0; i < word.length(); i++) {
            char letter = static_cast<char>(tolower(static_cast<unsigned char>(word.at(i))));
            if (isalpha(letter) || letter == '\'' || letter == '-') {
                alphaCount[letter - 'a'] += 1;
                wordLength++;
            }
        }
        if ((wordLength >= 1) && (wordLength <= 10)) letterCount[wordLength - 1] += 1;
    }

    cout << left << setw(15) << endl << "Word Length" << "Count" << endl;
    for (int i = 1; i <= 10; i++) cout << setw(15) << i << letterCount[i - 1] << endl;

    cout << endl << left << setw(15) << "Letter" << "Count" << endl;
    for (int i = 65; i <= 90; i++) cout << setw(15) << static_cast<char>(i) << alphaCount[i - 65] << endl;

    cout << endl;
    file.close();
	return 0;
}