//---------------------------------------------------------------------------
// patron.h
//---------------------------------------------------------------------------
// A Patron class to store information on Patrons of the library
// Patron name, ID, book rental history and currently checked out books
// are all stored.
// Patron Objects are initiated in the Patron Factory.
//
// Assumptions:
//  -- rentalHistory has no limit
//  -- currentCheckOuts has no limit
//  -- userID will be unique identifier
// Implementation:
//  -- rentalHistory Book objects are stored in a STL list
//  -- currentCheckOuts Book objects are stored in a STL list
//  -- Once a book is added to currentCheckOuts it is added to rentalHistory
//---------------------------------------------------------------------------

#pragma once
#include "Book.h"
#include <list>
#include <string>

using namespace std;

class Patron {
    /** overloaded << operator
     * @brief prints the Patron information to console
     */
    friend ostream& operator<<(ostream&, const Patron&);

public:
    // default constructor
    Patron();
    ~Patron();

    //---------------------------------------------------------------------------
        /** setPatron
         * @brief sets the userID, firstName and lastName of patron
         * @post Patron userID firstName lastName data members set
         * @param infile data from file
         */
    bool setPatron(istream& infile);

    //---------------------------------------------------------------------------
        /** getFirst
         * @brief retrieves and returns firstName
         * @return string firstName
         */
    string getFirst() const;

    //---------------------------------------------------------------------------
        /** getLast
         * @brief retrieves and returns lastName
         * @return string lastName
         */
    string getLast() const;

    //---------------------------------------------------------------------------
        /** getID
         * @brief retrieves and returns userID
         * @return int userID
         */
    int getID() const;

    //---------------------------------------------------------------------------
        /** hasBook
         * @brief checks if patron has a Book currently checked out
         * @pre a book in the current library
         * @post returns true if Patron has Book currently checked out
         * @param book the book target
         */
    Book* retrieve(istream&) const;

    //---------------------------------------------------------------------------
        /** getRentalHistory
         * @brief retrieves the rental history of Patron
         * @post Book list of bookHistory returned
         */
    list<Book*> getRentalHistory() const;

    //---------------------------------------------------------------------------
        /** printHistory
         * @brief prints the bookHistory to console
         * @post rentalHistory printed to console in order of events
         */
    void printHistory() const;

    //---------------------------------------------------------------------------
        /** getCurrentCheckOuts
         * @brief retrieves and returns the list of Book objects
         * @post Patron currentCheckOuts returned
         */
    list<Book*> getCurrentCheckOuts() const;

    //---------------------------------------------------------------------------
        /** printCurrentCheckOuts
         * @brief prints the list of currentCheckOuts to console
         * @post currentCheckOuts printed to console
         */
    void printCurrentCheckOuts() const;

    //---------------------------------------------------------------------------
        /** addCheckOut
         * @brief adds a Book object to currentCheckOuts list
         * @pre a valid Book in the library
         * @post currentCheckOuts contains new Book object item
         * @param book the Book to add
         */
    bool addCheckOut(const Book& book);

    //---------------------------------------------------------------------------
        /** returnBook
         * @brief removes a Book from currentCheckOuts
         * @pre a book currently checked out by Patron
         * @post book is removed from currentCheckOuts
         * @param book the Book object to remove
         */
    bool returnBook(const Book& book);

private:
    // private data members
    string firstName;
    string lastName;
    int userID;

    // list to store Patron book rental history
    list<Book*> bookHistory;

    // list to store Patron current check outs
    list<Book*> currentCheckOuts;

    /** addHistory
     * @brief adds a Book object to patron bookHistory
     * @pre book must be checked out by Patron
     * @post addHistory list now includes latest checkout
     * @return boolean value of successful addition to list
     * @param book the book to add to history
     */
    bool addHistory(const Book& book);
};
