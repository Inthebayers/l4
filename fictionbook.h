
//---------------------------------------------------------------------------
// fictionbook.h
//---------------------------------------------------------------------------
// A fiction book object. Handles the creation and storage of a fiction book,
// containing title, author, number of copies "owned" by the library, and
// copies of this book currently checked in.
//
// Assumptions:
//  -- initial character in input dictates 'f' for fiction
//---------------------------------------------------------------------------
#include "book.h"
#include <iostream>2

class FictionBook : public Book {
    /**
     * @brief Output operator overload for FictionBook object. Dictates output
     * formatting and functionality for a fiction book.
     *
     * @return ostream& containing information to be output in a formatted style
     * @pre: Assumes valid FictionBook object being passed in.
     * @post: none
     */
    friend ostream &operator<<(ostream &, const FictionBook &);

  public:
    /**
     * @brief Construct a new FictionBook object. Creates new fiction book with
     * title, author, and amount of books owned by library.
     *
     * @param title is the title of the book being created
     * @param author is the author of the book being created
     * @param totalTitlesOwned dictates the total amount of this book owned by
     * library
     * @pre: assumes object needs to be created
     * @post: fiction object will be destroyed, with memory freed
     */
    FictionBook(string title, string author, int totalTitlesOwned);

//---------------------------------------------------------------------------
    /**
     * @brief Destroy the FictionBook object.
     *
     * @pre: assumes valid object to be deleted
     * @post: object will be deleted & memory freed
     */
    ~FictionBook();

//---------------------------------------------------------------------------
    /**
     * @brief Creates a fiction book object, then returns a copy of that object
     * for the factory to function properly.
     *
     * @return FictionBook copy of newly created book object
     * @post: new fiction book object is created and returned.
     */
    FictionBook *create();
};
