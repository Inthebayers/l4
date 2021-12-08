//---------------------------------------------------------------------------
// book.h
//---------------------------------------------------------------------------
// Subclass of Item
// A book object. Handles the creation and storage of a
// book, containing title, author, number of copies "owned" by the library,
// and copies of this book currently checked in. Parent class of fictionbook,
// periodicalbook, and childrenbook.
//
// Assumptions:
// -- book copies will be initialized by subclass
// -- all books will have a title
// 
// Implementation:
// -- available and total copies initialized to 0 for generic book object
// -- subclasses will initialize total and available copies
//
//---------------------------------------------------------------------------

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "item.h"

using namespace std;

class Book : public Item
{
public:

    // default constructor
    Book();

    //---------------------------------------------------------------------------
    /**
    * @brief Destroy the Book object
    * @pre: Assumes valid object has been created
    * @post: Object will be deleted and memory freed.
    */
    virtual ~Book();    

    //---------------------------------------------------------------------------
    /** getTitle
    * @brief Get the title of the current book object.
    * @return string containing the title of the current book
    * @pre: Assumes valid book with title has been created.
    * @post: No changes.
    */
    string getTitle() const;

    //---------------------------------------------------------------------------
    /** setTitle
      * @brief Sets the title of the given book. 
      * @post book title set or changed 
      * @param incomingTitle title book will have
      */
    void setTitle(string incomingTitle);
    
protected:
    // title of book
    string title_;

    // copies of book checked into library
    int availableCopies_;

    // total amount of copies the library owns
    int totalCopies_;
};
#endif // !BOOK_H
