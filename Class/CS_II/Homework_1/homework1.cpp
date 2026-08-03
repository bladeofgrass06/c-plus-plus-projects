#include <fstream>
#include <string>
#include <iostream>

#include "library.cpp"

using namespace std;

int test1(Library* library) {
    library->displayLibrary();
    return 1;
}
int test2(Library* library) {
    library->addBook();
    library->displayLibrary();
    return 1;
}
int test3(Library* library) {
    library->removeBook();
    library->displayLibrary();
    return 1;
}
int test4(Library* library) {
    bool f1, f2, f3;
    library->addBook();
    cout << endl;
    f1 = library->searchBook("Ralph Waldo Emerson", 1);
    f2 = library->searchBook("The Odyssey", 2);
    f3 = library->searchBook("978-0-375-70224-2", 3);

    if (f1 && f2 && f3)  return 1;
    else                 return 0;
}

int main() {
    Library library;
    int tally = 0;

    ifstream inFile("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_II/Homework_1/library.txt");
    library.loadFromFile(inFile);

    char test = ' ';
    cout << endl << "Commence Test 1 (y/n)? ";
    cin >> test;

    if (test == 'y') tally += test1(&library);

    cout << "Commence Test 2 (y/n)? ";
    cin >> test;

    if (test == 'y') tally += test2(&library);

    cout << "Commence Test 3 (y/n)? ";
    cin >> test;

    if (test == 'y') tally += test3(&library);

    cout << "Commence Test 4 (y/n)? ";
    cin >> test;

    if (test == 'y') tally += test4(&library);
    cout << endl;

    ofstream outFile("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_II/Homework_1/output.txt");
    library.saveToFile(outFile);

    inFile.close();
    outFile.close();
    return 0;
}