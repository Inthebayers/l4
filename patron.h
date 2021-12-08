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

#ifndef PATRON_H
#define PATRON_H


#include "item.h"
#include "command.h"
#include <list>
#include <string>

using namespace std;

class Patron {

public:

    // default constructor
    Patron();

    // default constructor
    ~Patron();

    /** setPatron
    * @brief sets the userID, firstName and lastName of patron
    * @post Patron userID firstName lastName data members set
    * @param infile data from file
    * @param userID user ID passed from patron container
    */
    bool buildPatron(istream& infile, int userID);

    /** getFirst
    * @brief retrieves and returns firstName
    * @return string firstName
    */
    string getName() const;

    /** getID
    * @brief retrieves and returns userID
    * @return int userID
    */
    int getID() const;

    /** printHistory
    * @brief prints the itemHistory to console
    * @post rentalHistory printed to console in order of events
    */
    void printHistory();

    /** addHistory
    * @brief adds a Item object to patron itemHistory
    * @pre item must be checked out by Patron
    * @post addHistory list now includes latest checkout
    * @return boolean value of successful addition to list
    * @param item the item to add to history
    */
    bool addToHistory(Command*);

    /** searchCheckOuts
    * @brief searches checkout history to see if an item is viable for return
    * @return true if item is currently checked out by patron
    */
    bool searchCheckouts(const Item* target);

    /** displayPatron
    * @brief displays the patron information, ID, Last, First
    */
    void displayPatron();

private:

    // patron name
    string nameLastFirst_;

    //patron unique ID
    int userID_;

    // list to store Patron item rental history
    list<Command*> itemHistory;
};
#endif // !PATRON_H
