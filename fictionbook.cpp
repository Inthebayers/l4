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

bool FictionBook::operator<(const Book & rhsBook) const { 
    bool holder = false; 
        const FictionBook& rhsBookCasted = static_cast<const FictionBook&>(rhsBook);
    
    (getAuthor() < rhsBookCasted.getAuthor()) ? holder = true : holder = false;

    // if the book authors are the same, compare titles
    if (getAuthor() == rhsBookCasted.getAuthor()) {
        (getTitle() < rhsBookCasted.getTitle()) ? holder = true : holder = false;
    }

    return holder; 
}

bool FictionBook::operator>(const Book& rhsBook) const {
    bool holder = false;

    // cast book to fiction book 
    const FictionBook& rhsBookCasted = static_cast<const FictionBook&>(rhsBook);

    // compare titles, adjust bool as needed
    (getAuthor() > rhsBookCasted.getAuthor()) ? holder = true : holder = false;

    // if the book titles are the same compare authors
    if (getAuthor() == rhsBookCasted.getAuthor()) {
        (getTitle() > rhsBookCasted.getTitle()) ? holder = true : holder = false;
    }
    return holder;
}

   /**
     * Equals operator. Determines if two Book objects are equal.
     *
     * @param rhsBook rhs Book being passed in for equals comparison
     * @return true
     * @return false
     */
bool FictionBook::operator==(const Book& rhsBook) const {
    bool holder = false; 

    // cast rhs book to fiction book
    const FictionBook& rhsBookCasted = static_cast<const FictionBook&>(rhsBook);

    // compare author, title, and year between two books 
    if (rhsBookCasted.getAuthor() == getAuthor() && rhsBookCasted.getTitle() == getTitle() && rhsBookCasted.getYear() == getYear()) {
        holder = true; 
    }
    return holder;
}

   /**
     * Does not equals operator. Determines if two books are not equal.
     *
     * @param rhsBook
     * @return true
     * @return false
     */
bool FictionBook::operator!=(const Book& rhsBook) const {
    return !(*this == rhsBook);
}

// TODO: 
// [x] Less than operator < 
// [x] Greater than operator >
// [x] Equals to operator==
// [x] Does not equals operator!=
// [x] getYear
// [x] setYear
// [x] getAuthor
// [x] setAuthor
