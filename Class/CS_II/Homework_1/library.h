#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <fstream>

using namespace std;

struct Book {
	string author = "";
	string title = "";
	string isbn = "";
	Book* nextBook = nullptr;
};

class Library {
    private:
        unsigned int bookCount;	
        unsigned int inventorySize;
        Book* leadingBook;
    public:
        Library();
        ~Library();
        void loadFromFile(ifstream &file);
        void saveToFile(ofstream &file);
        void addBook();
        void removeBook();
        bool searchBook(string searchToken, int select);
        void displayLibrary();
};

#endif