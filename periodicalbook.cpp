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
// TODO needs spacing
void PeriodicalBook::display() const {
    cout << availableCopies_  << month_ << year_ << title_ << endl;
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
int PeriodicalBook::getYear() const {
    return year_;
}


//---------------------------------------------------------------------------
// overloaded comparison operators 
// Periodicals sorted by date (year, then month), then by title 
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// overloaded operator<
bool PeriodicalBook::operator<(const Book& rhsBook) const {
    bool holder = false;

    // cast book to preiodical book 
    const PeriodicalBook& rhsBookCasted = static_cast<const PeriodicalBook&>(rhsBook);

    // compare year
    if (year_ < rhsBookCasted.getYear()) {
        holder = true;
    }
    // if year is the same compare month
    else if (getYear() == rhsBookCasted.getYear()) {
        if (month_ < rhsBookCasted.getMonth()) {
            holder = true;
        }
        // if the month is the same compare title
        else if (month_ == rhsBookCasted.getMonth()) {
            if (title_ < rhsBookCasted.getTitle()) {
                holder = true;
            }
        }
    }

    return holder;
}

//---------------------------------------------------------------------------
// overloaded operator >

bool PeriodicalBook::operator>(const Book& rhsBook) const {
    bool holder = false;

    // cast book to preiodical book 
    const PeriodicalBook& rhsBookCasted = static_cast<const PeriodicalBook&>(rhsBook);

    // compare year
    if (year_ > rhsBookCasted.getYear()) {
        holder = true;
    }
    // if year is the same compare month
    else if (getYear() == rhsBookCasted.getYear()) {
        if (month_ > rhsBookCasted.getMonth()) {
            holder = true;
        }
        // if the month is the same compare title
        else if (month_ == rhsBookCasted.getMonth()) {
            if (title_ > rhsBookCasted.getTitle()) {
                holder = true;
            }
        }
    }

    return holder;
}

//---------------------------------------------------------------------------
// overloaded operator==
bool PeriodicalBook::operator==(const Book& rhsBook) const {
    bool holder = false;
    // check if it's the same object
    if (this == rhsBook) {
        return true;
    }
    // cast rhs book to periodical's book
    const PeriodicalBook& rhsBookCasted = static_cast<const PeriodicalBook&>(rhsBook);

    // compare year, month, title
    if (year_ == rhsBookCasted.getYear && month_ == rhsBookCasted.getMonth() && title_ == rhsBookCasted.getTitle()) {
        holder = true;
    }

    return holder;
}

//---------------------------------------------------------------------------
// overloaded operator!=
bool PeriodicalBook::operator!=(const Book& rhsBook) const {
    // use comparison operator to return value
    return (!*this == rhsBook);
}


// TODO: 
// [x] Less than operator < 
// [x] Greater than operator >
// [x] Equals to operator==
// [x] Does not equals operator!=
// [x] getYear
// [x] setYear
// [x] getAuthor - no author
// [x] setAuthor - no author 
// [x] COPY CONSTRUCTOR - not necessary