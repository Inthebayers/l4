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
#include "item.h"

using namespace std;

class Book : public Item {
public:
    ///**
    // * @brief Construct a new Book object
    // *
    // * @param title of book being created
    // * @param bookCode code of book being created to determine type of book
    // */
    //Book(string title, char bookCode);

    /**
     * Default constructor
     */
    Book();

    //---------------------------------------------------------------------------
     /**
      * @brief Destroy the Book object
      *
      * @pre: Assumes valid object has been created
      * @post: Object will be deleted and memory freed.
      */
    virtual ~Book();

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

    /**
     * Gets the title of the given book. Pure virtual.
     */
    virtual string getTitle() = 0;

    /**
     * Sets the title of the given book. Pure virtual.
     */
    virtual void setTitle() = 0;

    virtual void display() = 0; 

    /**
    * Less than operator. Compares LHS and RHS for lesser value.
    * @param rhsBook rhs Book being passed in
    * @return true
    * @return false
    */
    virtual bool operator<(const Book*& rhsBook) = 0;

    /**
     *
     * Greater than operator. compares LHS and RHS for greater value.
     * @param rhsBook rhs Book being passed in for comparison
     * @return true
     * @return false
     */
    virtual bool operator>(const Book*& rhsBook) = 0;

    /**
     * Equals operator. Determines if two Book objects are equal.
     *
     * @param rhsBook rhs Book being passed in for equals comparison
     * @return true
     * @return false
     */
    virtual bool operator==(const Book*& rhsBook) = 0;

    /**
     * Does not equals operator. Determines if two books are not equal.
     *
     * @param rhsBook
     * @return true
     * @return false
     */
    virtual bool operator!=(const Book*& rhsBook) = 0;
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
