//---------------------------------------------------------------------------
// book.h
//---------------------------------------------------------------------------
// A book object. Handles the creation and storage of a
// book, containing title, author, number of copies "owned" by the library,
// and copies of this book currently checked in. Parent class of fictionbook,
// periodicalbook, and childrenbook.
//
// Assumptions:
// -- All books will have 5 copies in the library
//
//---------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "item.h"

using namespace std;

class Book : public Item
{
public:
    ///**
    // * @brief Construct a new Book object
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
       * @pre: Assumes valid object has been created
       * @post: Object will be deleted and memory freed.
       */
    virtual ~Book();    //---------------------------------------------------------------------------
    /**
       * @brief Handles the field management required to check out a book.
       * @return true if check out was successful
       * @return false if check out was not sucessful
       * @pre: Assumes book has amount to check out
       * @post: Book will remove 1 copy of itself from the library stores
       */
    virtual bool checkOut();
    // TODO: Likely won't need, will be in commands

       //---------------------------------------------------------------------------
       /**
          * @brief Returns book copy to library, adjusting values for currently
          * checked in copies.
          * @return true if value is modified
          * @return false if value is not modified
          * @pre: Assumes book is checked out
          * @post: Book is returned to library, incrementing the number of copies
          */
    bool returnToLibrary();

    //---------------------------------------------------------------------------
    /**
       * @brief Get the title of the current book object.
       * @return string containing the title of the current book
       * @pre: Assumes valid book with title has been created.
       * @post: No changes.
       */
    string getTitle() const;

    /**
      * Sets the title of the given book. Pure virtual.
      */
    void setTitle(string incomingTitle);

    /**
     * @brief Set the number of available copies within a book to a set amount passed     * in by parameter.
     *     * @param int, the number of books that should be set available after function.     */
    void setAvailableCopies(int);    
    /**
     * @brief Get the amount of available copies of this given book.
     *     * @return int, the amount of books currently checked in and available.     */
    int getAvailableCopies() const;

    /**
     * @brief Set the total amount of copies owned by the library, whether checked
     * in or out.     *     * @return true if set was successful
     * @return false if set was unsuccessful
     */
    bool setTotalCopies(int);

    /**
     * @brief Get the total number of copies of a book owned by the library, whether
     * checked in or out.     *     * @return int of total number of copies of book owned by library.     */
    int getTotalCopies();

protected:
    // title of book
    string title_;

    static const int COPIES = 5;
    // copies of book checked into library
    int availableCopies_ = COPIES;
    // total amount of copies the library owns
    int totalCopies_ = COPIES;
};
