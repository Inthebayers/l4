
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

ostream& operator<<(ostream& out, const FictionBook& theBook) {
    
}

//default constructor 
FictionBook::FictionBook() {
    author_ = "";
    year_ = 0;
    title_ = "";
    book_code_ = "f";
    number_checked_in_ = 0;
    totalTitlesOwned = 0;
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
// !!!!!!!! add in spacing later
void FictionBook::display() {
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
string FictionBook::getAuthor() {
    return author_;
}

//---------------------------------------------------------------------------
// getYear
int FictionBook::getYear() {
    return year_;
}

