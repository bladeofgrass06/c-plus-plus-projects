#include <iostream>

using namespace std;

int main() {
	int templateArray[100] = {0}, resultArray[100] = {0}, sum = 0;
    templateArray[50] = 1;

    for (int i = 0; i < 100; i++) cout << templateArray[i] << " ";
    cout << endl;

    for (int i = 0; i < 64; i++) {
        for (int i = 1; i < 100; i++) {
            if (i < 98)        sum = templateArray[i] + templateArray[i + 1] + templateArray[i + 2];
            else if (i == 98)  sum = templateArray[i] + templateArray[i + 1];
            else               sum = templateArray[i];

            sum == 1 ? resultArray[i + 1] = 1 : resultArray[i + 1] = 0;
            templateArray[i] = resultArray[i];
        }
        for (int i = 0; i < 100; i++) cout << resultArray[i] << " ";
        cout << endl;
    }
	return 0;
}