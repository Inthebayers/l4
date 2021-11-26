//---------------------------------------------------------------------------
// library.h
//---------------------------------------------------------------------------
// Library class acts as manager
//
// Assumptions:
//  -- correctly formatted input from file
//  -- each book item is uniquely identified by its srting criteria
// Implementation:
//  -- holds a factory, container, and bookcase
//---------------------------------------------------------------------------

#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "bookcase.h"
#include "bookfactory.h"
#include "command.h"
#include "patroncontainer.h"
#include <iostream>

using namespace std;

class Library {
  public:
    // initialize commands here and set indexes of commands[]
    Library(); // default constructor
    ~Library(); // default destructor

//---------------------------------------------------------------------------
    /** addPatron
     * @brief adds patron to patron container
     * @return true if patron was added, false if not
     * @param istream patron info from file
     */
    bool addPatron(istream &);

//---------------------------------------------------------------------------
    /** getPatronHistory
     * @brief prints patron book history to console
     * @param patron to get history from
     */
    void getPatronHistory(const Patron &) const;

//---------------------------------------------------------------------------
    /** addBook
     * @brief adds book to book container
     * @return true if book was added, false if not
     */
    bool addBook(istream &);

//---------------------------------------------------------------------------
    /** displayContents
     * @brief displays books by category, sorted within the category
     */
    void displayContents() const;

//---------------------------------------------------------------------------
    /** commandHandler
     * @brief handles the commands given from the file, calls checkout book,
     *        check in book, and displayContents as needed
     */
    void commandHandler(istream &);

  private:
    /** hash
     * @brief hashes letters to ints. A...Z to 0...25
     * @return int that is element of commands array
     * @param char representing command to be hashed
     */
    int hash(char &const) const;

    // private data memebers
    BookFactory factory;
    PatronContainer container;
    Bookcase bookcase;
    Command *commands[26];
};

#endif
