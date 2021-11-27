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
using namespace std;

class Book : public Item {


    virtual bool operator<(const Book*& rhsBook) = 0;

    virtual bool operator>(const Book*& rhsBook) = 0;

    virtual bool operator==(const Book*& rhsBook) = 0;

    virtual bool operator!=(const Book*& rhsBook) = 0;

    /**
     * @brief Output operator overload for PeriodicalBook object. Dictates
     * output formatting and functionality for a periodical book.
     *
     * @return ostream& containing information to be output in a formatted style
     * @pre: Assumes valid FictionBook object being passed in.
     * @post: Data not changed, but is output.
     */
    friend ostream &operator<<(ostream &, const Book &);

  public:
    /**
     * @brief Construct a new Book object
     *
     * @param title of book being created
     * @param bookCode code of book being created to determine type of book
     */
    Book(string title, char bookCode);
   
   //---------------------------------------------------------------------------
    /**
     * @brief Destroy the Book object
     *
     * @pre: Assumes valid object has been created
     * @post: Object will be deleted and memory freed.
     */
    virtual ~Book() = 0;

   //---------------------------------------------------------------------------
    /**
     * @brief Handles the field management required to check out a book.
     *
     * @return true if check out was successful
     * @return false if check out was not sucessful
     *
     * @pre: Assumes book has amount to check out
     * @post: Book will remove 1 copy of itself from the library stores
     */
    virtual bool checkOut() = 0;

   //---------------------------------------------------------------------------
    /**
     * @brief Get the title of the current book object.
     *
     * @return string containing the title of the current book
     *
     * @pre: Assumes valid book with title has been created.
     * @post: No changes.
     */
    virtual string getTitle() const = 0;

   //---------------------------------------------------------------------------
    /**
     * @brief Returns book copy to library, adjusting values for currently
     * checked in copies.
     *
     * @return true if value is modified
     * @return false if value is not modified
     *
     * @pre: Assumes book is checked out
     * @post: Book is returned to library, incrementing the number of copies
     */
    virtual bool returnToLibrary() = 0;

   //---------------------------------------------------------------------------
    /**
     * @brief Get the code/genre of the book for hashing purposes.
     *
     * @return char corresponding to the code/genre of the book.
     *
     * @pre: Assumes valid code and properly created book.
     * @post: No changes to data.
     */
    virtual char getBookCode() const = 0;

  private:
    // title of book
    string title;

    // code of book
    char bookCode;

    // copies of book checked into library
    int numberCheckedIn;

    // total amount of copies the library owns
    int totalTitlesOwned;

    // default booktype
    char bookType = 'H';
};
