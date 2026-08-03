// Name: Noah Borden
// Due Date: 1/5/2025
// Project: Homework 1 - create a library program implementing
// classes, structs, and linked lists in order to add, delete, and
// and organize data

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "library.h"

using namespace std;

Library::Library() {
    bookCount = 0;
    inventorySize = 0;
    leadingBook = nullptr;
}

Library::~Library() {
    Book* current = leadingBook;
    while (current) {
        Book* next = current->nextBook;
        delete current;
        current = next;
    }
}

void Library::loadFromFile(ifstream &file) {
    if (!file) {
        cerr << "Error: File 'library.txt' not found!" << endl;
        file.close();
        exit(0);
    }
    
    string line = "", author = "", title = "", isbn = "";
    while(getline(file, line)) {
        stringstream ss(line);
        getline(ss, author, ',');
        getline(ss, title, ',');
        getline(ss, isbn, ',');

        Book* new_book = new Book;
        new_book->author = author;
        new_book->title = title;
        new_book->isbn = isbn;

        if (!leadingBook) leadingBook = new_book;
        else {
            Book* temporary = leadingBook;
            while (temporary->nextBook) temporary = temporary->nextBook;
            temporary->nextBook = new_book;
        }
        bookCount++;
    }
}

void Library::saveToFile(ofstream &file) {
    if (!file) {
        cerr << "Error: File 'output.txt' not found!" << endl;
        file.close();
        exit(0);
    }
    
    Book* current = leadingBook;
    while (current) {
        file << current->author << endl << current->title << endl << current->isbn << endl;
        current = current->nextBook;
    }
}

void Library::addBook() {
    cin.ignore();
    string title = "", author = "", isbn = "";
    
    cout << endl;
    cout << "Enter a title: ";
    getline(cin, title);
    cout << "Enter an author: ";
    getline(cin, author);
    cout << "Enter an ISBN: ";
    getline(cin, isbn);

    Book* new_book = new Book;
    new_book->author = author;
    new_book->title = title;
    new_book->isbn = isbn;
    
    if (!leadingBook) leadingBook = new_book;
    else {
        Book* temporary = leadingBook;
        while (temporary->nextBook) temporary = temporary->nextBook;
        temporary->nextBook = new_book;
    }
    bookCount++;

    cout << endl << "Book added successfully!" << endl;
}

void Library::removeBook() {
    cin.ignore();

    string isbn = "";
    cout << endl << "Enter an ISBN: ";
    getline(cin, isbn);

    Book* current = leadingBook;
    Book* previous = nullptr;

    while (current) {
        if (current->isbn == isbn) {
            if (previous)  previous->nextBook = current->nextBook;
            else           leadingBook = current->nextBook;
            
            delete current;
            bookCount--;
            cout << endl << "Book deleted successfully!" << endl;
            return;
        }
        previous = current;
        current = current->nextBook;
    }
    cout << endl << "The book was not found!" << endl;
}

bool Library::searchBook(string search_token, int select) {
    Book* current = leadingBook;
    while (current) {
        if (((select == 1) && (current->author == search_token)) || 
            ((select == 2) && (current->title == search_token)) || 
            ((select == 3) && (current->isbn == search_token))) {
                cout << current->title << " by " << current->author << " (ISBN: " << current->isbn 
                     << ") was found!" << endl;
                return true;
        }
        current = current->nextBook;
    }
    cout << endl << "The book was not found!" << endl << endl;
    return false;
}
   
void Library::displayLibrary() {
    Book* current = leadingBook;
    while (current) {
        cout << endl << "Title: " << current->title 
             << endl << "Author: " << current->author 
             << endl << "ISBN: " << current->isbn 
             << endl;
        current = current->nextBook;
    }
    cout << endl;
}