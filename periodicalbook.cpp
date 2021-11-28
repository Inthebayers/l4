
//---------------------------------------------------------------------------
// periodicalbook.cpp
//---------------------------------------------------------------------------
// A periodical book object. Handles the creation and storage of a periodical
// book, containing title, author, number of copies "owned" by the library,
// and copies of this book currently checked in.
//
// Assumptions:
//  -- initial character in input dictates 'p' for periodical
//---------------------------------------------------------------------------
#include "periodicalbook.h"

//---------------------------------------------------------------------------
// default constructor
PeriodicalBook::PeriodicalBook() {
    month_ = 0;
    year_ = 0;
    title_ = "";
    bookCode_ = "P";
}

//---------------------------------------------------------------------------
// destructor
PeriodicalBook:: ~PeriodicalBook() {

}

//---------------------------------------------------------------------------
// create
Book* PeriodicalBook::create() {
    return new PeriodicalBook();
}

//---------------------------------------------------------------------------
// display
//!!! needs spacing
void PeriodicalBook::display() const {
    cout << availableCopies_ << title_ << month_ << year_ << endl;
}

//---------------------------------------------------------------------------
//setMonth
bool PeriodicalBook::setMonth(int month) {
    bool success = false;
    if (month > 0 && month <= 12) {
        month_ = month;
        success = true;
    }
    return success;
}

//---------------------------------------------------------------------------
// getMonth
bool PeriodicalBook::getMonth() const {
    return month_;
}

//---------------------------------------------------------------------------
//setYear
bool PeriodicalBook::setYear(int year) {
    bool success = false;
    if (year > 0) {
        year_ = year;
        success = true;
    }
    return success;
}

//---------------------------------------------------------------------------
//getYear
int PeriodicalBook::getYear() {
    return year_;
}
