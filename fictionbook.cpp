
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

ostream& operator<<(ostream&, const FictionBook&) {

}

// probably wont need this 
FictionBook::FictionBook(string author, string title, int year, int totalTitlesOwned) {

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
//setAuthor
void FictionBook::setAuthor() {

}
