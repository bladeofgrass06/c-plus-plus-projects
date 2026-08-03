#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
	string sentence = "", word = "", ecnetnes = "";

    cout << endl << "Enter a sentence: ";
    getline(cin, sentence);
    istringstream iss(sentence);
    
    while (iss >> word) {
        if (word.back() == '.' || word.back() == ',' || word.back() == '!' || 
            word.back() == '?' || word.back() == '*' || word.back() == '%') {
                word.insert(0, string(1, word.back()));
                word = word.substr(0, word.length() - 1);
        }
        if ((word.front() == '#') || (word.front() == '$')) {
            word.insert(word.length(), string(1, word.front()));
            word = word.substr(1, word.length());
        }
        if (word != sentence.substr(0, sentence.find(' ')))
            ecnetnes.insert(0, " ");
        ecnetnes.insert(0, word);
    }

    cout << "The reversed sentence is '" << ecnetnes << "'." << endl << endl;
	return 0;
}