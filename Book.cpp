//---------------------------------------------------------------------------
// book.h
//---------------------------------------------------------------------------
// A book object. Handles the creation and storage of a
// book, containing title, author, number of copies "owned" by the library,
// and copies of this book currently checked in. Parent class of fictionbook,
// periodicalbook, and childrenbook.
//
//---------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "book.h"
using namespace std;

class Book {

    /**
     * @brief Output operator overload for PeriodicalBook object. Dictates
     * output formatting and functionality for a periodical book.
     *
     * @return ostream& containing information to be output in a formatted style
     * @pre: Assumes valid FictionBook object being passed in.
     * @post: Data not changed, but is output.
     */
    friend ostream& operator<<(ostream&, const Book&);

public:
    /**
     * @brief Construct a new Book object
     *
     * @param title of book being created
     * @param bookCode code of book being created to determine type of book
     */
    Book(string incTitle, char incBookCode) {
        // set title to incoming title
        title = title;

        bookCode = bookCode;

    }

    Book::Book()
    {
    }

    //---------------------------------------------------------------------------
     /**
      * @brief Destroy the Book object
      *
      * @pre: Assumes valid object has been created
      * @post: Object will be deleted and memory freed.
      */
    virtual ~Book() {
    }

    //---------------------------------------------------------------------------
     /**
      * @brief Get the code/genre of the book for hashing purposes.
      *
      * @return char corresponding to the code/genre of the book.
      *
      * @pre: Assumes valid code and properly created book.
      * @post: No changes to data.
      */
    char getBookCode() const;



private:
    // title of book
    string title_;

    // code of book
    char bookCode_;

    // copies of book checked into library
    int numberCheckedIn_;

    // total amount of copies the library owns
    int totalTitlesOwned_;

    // default booktype
    char bookType_ = 'H';
};
