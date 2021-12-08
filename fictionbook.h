//---------------------------------------------------------------------------
// fictionbook.h
//---------------------------------------------------------------------------
// A fiction book object. Handles the creation and storage of a fiction book,
// containing title, author, number of copies "owned" by the library, and
// copies of this book currently checked in.
//
// Ficiton sorted by author, then title
//
// Assumptions:
//  -- initial character in input dictates 'f' for fiction
//---------------------------------------------------------------------------

#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

#include "book.h"
#include <iostream>

class FictionBook : public Book {

  public:
    /** constructor
     * @brief Construct a new FictionBook object
     * @pre: assumes object needs to be created
     * @post: new FictionBook object
     */
    FictionBook();

    /** destructor
     * @brief Destroy the FictionBook object.
     * @pre: assumes valid object to be deleted
     * @post: object will be deleted & memory freed
     */
    ~FictionBook();

    /** buildItem
     * @brief creates book object reading from data file
     * @pre: A correctly formatted open data file
     * @post: a new book object
     */
    bool buildItem(istream &in);

    /** create
     * @brief Creates a fiction book object, then returns a copy of that object
     * for the factory to function properly.
     * @return FictionBook copy of newly created book object
     * @post: new fiction book object is created and returned.
     */
    virtual Item *create();

    /** fill
     * @brief fills data for a fictionBook item from Command Data file format
     * @pre an empty ChildrenBook item
     * @post only author and title data fields are set
     */
    virtual void fill(istream &);

    /** displayBookHeader
     * @brief displays the categories and format of data for fictionBook list
     * @pre none
     * @post Children book item list header printed to cout
     */
    virtual void displayBookHeader() const;

    /** diaplay
     * @brief displays the information of the current book in sort order
     * @pre a non-empty book object
     * @post contents displayed to console,
     */
    virtual void display() const;

    /** errorDisplay
     * @brief handles the ouput of an invalid FictionBook's - prints to console
     * @pre FicitonBook object has title_ and author_ set
     * @post error messaged displayed
     */
    virtual void errorDisplay() const;

    /** historyDisplay
     * @brief formats the output when FictionBook Item is displayed from patron
     * history list
     * @pre FictionBook Item previously added to patron history
     * @post data members printed to console in history format
     */
    virtual void historyDisplay() const;

    /** getCopiesAvailable
     * @brief gets and returns the available copies of this object
     * @pre none
     * @post availableCopies_ returned
     * @return int of availableCopies_
     */
    virtual int getCopiesAvailable() const;

    /** setAuthor
     * @brief sets the author data member of the book
     * @pre a new book object
     * @post a book object with a set author
     */
    void setAuthor(string author);
    /** setYear
     * @brief sets the year data member
     * @pre a new book object
     * @post a book object with a published year
     */
    bool setYear(int year);

    /** getAuthor
     * @brief gets and returns the book author
     * @pre book object has set author
     * @post string of author is returned
     */
    string getAuthor() const;

    /** getYear
     * @brief returns the book published year
     * @pre a book object with set year
     * @post int year is returned
     */
    int getYear() const;

    /** changeAvailable
     * @brief increment or decrement availableCopies_
     * @pre Childrenbook to be checkedOut or returned by patron
     * @post availableCopies_ value changes by 1
     * @return bool true if successful
     */
    virtual bool changeAvailable(int num);

//---------------------------------------------------------------------------
// Overloaded Operators
//---------------------------------------------------------------------------

    /**
     * Less than operator. Compares LHS and RHS for lesser value.
     * @param rhsItem rhs Book being passed in
     * @return true
     * @return false
     */
    bool operator<(const Item &rhsItem) const;

    /**
     *
     * Greater than operator. compares LHS and RHS for greater value.
     * @param rhsItem rhs Book being passed in for comparison
     * @return true
     * @return false
     */
    bool operator>(const Item &rhsItem) const;

    /**
     * Equals operator. Determines if two Book objects are equal.
     *
     * @param rhsItem rhs Book being passed in for equals comparison
     * @return true
     * @return false
     */
    bool operator==(const Item &rhsItem) const;

    /**
     * Does not equals operator. Determines if two books are not equal.
     *
     * @param rhsItem
     * @return true
     * @return false
     */

    bool operator!=(const Item &rhsItem) const;

  private:
    // author of the book, last then first name
    string author_;

    // publishing year
    int year_;

    // default copies available
    static const int COPIES = 5;
};
#endif // !FICTIONBOOK_H
