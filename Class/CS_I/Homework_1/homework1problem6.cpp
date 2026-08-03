#include <iostream>

using namespace std;

int main() {
	int number = 57, guess = 0;
    
	while (guess != number) {
	    cout << endl << "Guess a number from 1 to 100: ";
		cin >> guess;
		if (guess < number) 	  cout << "Guess is too low." << endl;
		else if (guess > number)  cout << "Guess is too high." << endl;
	}

	cout << "Congratulations! You guessed the magic number." << endl << endl;
	return 0;
}