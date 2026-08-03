#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<float> grades = {};
    float grade = 0;

    cout << endl;

    while (grade != -1) {
        cout << "Enter a grade from 0 to 100. Enter -1 to finish: ";
        cin >> grade;
        if (grade != -1) {
            if ((grade < 0) || (grade > 100)) cerr << "Error: Invalid grade!" << endl;
            else {
                printf("You entered %.2f.\n", grade);
                grades.push_back(grade);
            }
        }
    }

    auto lowest = min_element(grades.begin(), grades.end());
    printf("\nThe lowest grade will be dropped, which is %.2f.\n", *lowest);
    grades.erase(lowest);

    printf("The average of the other grades is %.2f.\n\n", 
        accumulate(grades.begin(), grades.end(), 0.0f) / static_cast<float>(grades.size()));

	return 0;
}