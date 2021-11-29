//---------------------------------------------------------------------------
// fictionbook.cpp
//---------------------------------------------------------------------------
// A fiction book object. Handles the creation and storage of a fiction book,
// containing title, author, number of copies "owned" by the library, and
// copies of this book currently checked in.
//
// Implementation:
//  -- initial character in input dictates 'f' for fiction
//---------------------------------------------------------------------------
#include "fictionbook.h"

//default constructor
FictionBook::FictionBook() {
    author_ = "";
    year_ = 0;
    title_ = "";
    bookCode_ = 'F';
}

//destructor
FictionBook::~FictionBook() {
}

//---------------------------------------------------------------------------
// create
Book* FictionBook::create() {
    return new FictionBook();
}

//---------------------------------------------------------------------------
//display
// TODO: Add spacing
void FictionBook::display() const {
    cout << availableCopies_ << author_ << title_ << year_ << endl;
}

//---------------------------------------------------------------------------
//setAuthor
void FictionBook::setAuthor(string author) {
    author_ = author;
}

//---------------------------------------------------------------------------
// setYear
bool FictionBook::setYear(int year) {
    bool success = false;
    if (year > 0) {
        year_ = year;
        success = true;
    }
    return success;
}

//---------------------------------------------------------------------------
// getAuthor
string FictionBook::getAuthor() const {
    return author_;
}

//---------------------------------------------------------------------------
// getYear
int FictionBook::getYear() const {
    return year_;
}

bool FictionBook::operator<(const FictionBook *& rhsBook) { 
    bool holder = false; 
    (getAuthor() < rhsBook->getAuthor())
}

// TODO: 
// [ ] Less than operator < 
// [ ] Greater than operator >
// [ ] Equals to operator==
// [ ] Does not equals operator!=
// [ ] getYear
// [ ] setYear
// [ ] getAuthor
// [ ] setAuthor
// TODO: COPY CONSTRUCTOR