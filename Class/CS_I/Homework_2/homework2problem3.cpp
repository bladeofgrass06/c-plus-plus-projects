#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

int main() {
    string sentence = "", word = "";

    cout << endl << "Enter a sentence: ";
    getline(cin, sentence);
    istringstream iss(sentence);

    float sum = 0;
    while (iss >> word)
        try                                { sum += stof(word); }
        catch (const invalid_argument& e)  { /* Skip word */ }

    cout << "The sum is " << sum << "." << endl << endl;
    return 0;
}