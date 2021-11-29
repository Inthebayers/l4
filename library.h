//---------------------------------------------------------------------------
// library.h
//---------------------------------------------------------------------------
// Library class acts as interface between data files and storage / functions
//
// Assumptions:
// -- correctly formatted input from file
// -- each book item is uniquely identified by its srting criteria
// -- each command is uniquely and correctly identified by command char
// Implementation:
// -- holds a book factory, command factory, patron container, and bookcase
// -- Library reads input from data files
//---------------------------------------------------------------------------

#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "bookcase.h"
#include "bookfactory.h"
#include "command.h"
#include "commandfactory.h"
#include "patroncontainer.h"
#include <iostream>

using namespace std;

class Library {
public:

    // default constructor
    Library(); 

    // default destructor
    ~Library(); 

//---------------------------------------------------------------------------
    /** addPatron
     * @brief adds patron to patron container
     * @return true if patron was added, false if not
     * @param istream patron info from file
     */
    bool buildPatrons(istream&);

//---------------------------------------------------------------------------
    /** getPatronHistory
    * @brief prints patron book history to console
    * @param patron to get history from
    */
    void printPatronHistory(const Patron&) const;

//---------------------------------------------------------------------------
    /** addBook
    * @brief adds book to book container
    * @return true if book was added, false if not
    */
    bool buildBooks(istream&);

//---------------------------------------------------------------------------
    /** displayContents
    * @brief displays books by category, sorted within the category
    */
    void displayItems() const;

//---------------------------------------------------------------------------
    /** commandHandler
    * @brief reads command codes and calls command factory
    */
    void commandHandler(istream&);

private:

    // private data memebers
    BookFactory bookFactory;
    CommandFactory commFactory;
    PatronContainer patronContainer;
    Bookcase bookcase;

};

#endif
// TODO go through and delete uneccessary destructors - no strings & no dynamic memory
// TODO other functions we want in this class? from assignment