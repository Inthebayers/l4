//---------------------------------------------------------------------------
// childrenbook.h
//---------------------------------------------------------------------------
// A children book object. Handles the creation and storage of a children's
// book, containing title, author, number of copies "owned" by the library,
// and copies of this book currently checked in.
//
// Assumptions:
//  -- initial character in input dictates 'c' for children
//---------------------------------------------------------------------------
#include "book.h"
#include <iostream>

class ChildrenBook : public Book {
    //---------------------------------------------------------------------------
     /**
      * @brief Output operator overload for ChildrenBook object. Dictates output
      * formatting and functionality for a fiction book.
      *
      * @return ostream& containing information to be output in a formatted style
      * @pre: Assumes valid FictionBook object being passed in.
      * @post: Data not changed, but is output.
      */
    friend ostream& operator<<(ostream&, const ChildrenBook&);

public:
    /**
     * @brief Construct a new Children object. Creates new fiction book with
     * title, author, and amount of books owned by library.
     *
     * @param title is the title of the book being created
     * @param author is the author of the book being created
     * @param year the publishing year
     * @param totalTitlesOwned dictates the total amount of this book owned
     * by library
     * @pre: assumes object needs to be created
     * @post: fiction object will be destroyed, with memory freed
     */
    ChildrenBook();

    //---------------------------------------------------------------------------
     /**
      * @brief Destroy the Children Book object.
      *
      * @pre: Assumes valid ChildrenBook object is created.
      * @post: ChildrenBook object will be deleted, with memory freed.
      */
    ~ChildrenBook();

    //---------------------------------------------------------------------------
     /** create
      * @brief Creates a children book object, then returns a copy of that object
      * for the factory to function properly.
      *
      * @return ChildrenBook copy of newly created book object
      * @post: new children book object is created and returned.
      */
    virtual Book* create();

    /** setAuthor
     * @brief sets the book author
     * @pre a new book object
     * @post book author stored in data member
     */
    void setAuthor(string author);

    /** getAuthor
     * @brief gets and returns the book author
     * @pre book object has set author
     * @post string of authro is returned
     */
    string getAuthor() const;

    /** setYear
     * @brief sets the year data member
     * @pre a new book object
     * @post a book object with a published year
     */
    void setYear(int year);

    /** getYear
     * @brief returns the book published year
     * @pre a book object with set year
     * @post int year is returned
     */
    int getYear() const;

private:
    // author of the book, last then first
    string author_;

    //publishing year
    int year_;

};
