#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string reverseWord(string &word) {
	string drow = "";
	for (const char& c : word) drow.insert(0, string(1, c));
	return drow;
}

int main() {
	ifstream wordsearch("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_4/word_puzzle_2D_problem_six.txt");
	ifstream dictionary("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_4/dictionary_four_letter_words.txt");
	if (!wordsearch || !dictionary) {
		cout << endl;
		if (!wordsearch) cerr << "Error: 'word_puzzle_2D_problem_six.txt' failed to open!" << endl;
		if (!dictionary) cout << "Error: 'dictionary_four_letter_words.txt' failed to open!" << endl;
		cout << endl;
		wordsearch.close();
		dictionary.close();
		return 0;
	}

	char puzzle[10][10] = {' '};
    string line = "";
	for (int row = 0; row < 10; row++) {
		getline(wordsearch, line);
        for (int col = 0; col < 10; col++)
        	puzzle[row][col] = line[col];
	}

	cout << endl;

	int horWords = 0, verWords = 0;

    for (int row = 0; row < 10; row++) {
        for (int col = 0; col <= 6; col++) {
            string horWord = "";
            for (int n = 0; n < 4; n++) horWord += puzzle[row][col + n];
			string dictWord = "";
            while (dictionary >> dictWord)
				if ((horWord == dictWord) || (reverseWord(horWord) == dictWord)) {
					cout << dictWord << endl;
					horWords++;
				}
			dictionary.clear();
			dictionary.seekg(0, ios::beg);
        }
    }

	cout << endl << horWords << " horizontal words were found in the wordsearch." << endl << endl;

    for (int col = 0; col < 10; col++) {
        for (int row = 0; row <= 6; row++) {
            string verWord = "";
            for (int n = 0; n < 4; n++) verWord += puzzle[row + n][col];
			string dictWord = "";
            while (dictionary >> dictWord)
				if ((verWord == dictWord) || (reverseWord(verWord) == dictWord)) {
					cout << dictWord << endl;
					verWords++;
				}
			dictionary.clear();
			dictionary.seekg(0, ios::beg);
        }
    }

	cout << endl << verWords << " vertical words were found in the wordsearch." << endl << endl;
	
	wordsearch.close();
	dictionary.close();
	return 0;
}