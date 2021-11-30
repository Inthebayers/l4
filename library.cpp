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

#include "library.h"

//---------------------------------------------------------------------------
// constructor
Library::Library() {

}

//---------------------------------------------------------------------------
// destructor
Library::~Library() {
}

//---------------------------------------------------------------------------
// buildPatron
//bool Library::buildPatrons(istream& in) {
//    // data format --> ID# Last First
//    //return patronContainer.insert(in);
//    // no patron factory - create patron object here?
//    return false;
//}

//---------------------------------------------------------------------------
// printPatronHistory
//void Library::printPatronHistory(const Patron&) const {
    //TODO do we want to go directly to patron? or access through patron container
//}

//---------------------------------------------------------------------------
// buildBook
bool Library::buildBooks(istream& in) {
   return bookcase.buildBook(in);
}


//---------------------------------------------------------------------------
// displayItems
void Library::displayBooks() const {
    bookcase.display();
}

//---------------------------------------------------------------------------
// commandHandler
void Library::commandHandler(istream& in) {

}

//---------------------------------------------------------------------------
//