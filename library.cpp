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

#include "library.h"

//---------------------------------------------------------------------------
// constructor
Library::Library() {
    bookFactory = new BookFactory();
    commFactory = new CommandFactory();
    patronContainer = new PatronContainer();
    bookcase = new Bookcase();

}

//---------------------------------------------------------------------------
// destructor
Library::~Library() {
    // deallocate all new memory
    delete bookFactory;
    delete commFactory;
    delete patronContainer;
    delete bookcase;
}

//---------------------------------------------------------------------------
// addPatron
bool Library::buildPatrons(istream& in) {
    // data format --> ID# Last First
    return patronContainer.insert(in);
}

//---------------------------------------------------------------------------
// printPatronHistory
void Library::printPatronHistory(const Patron&) const {
    //TODO do we want to go directly to patron? or access through patron container
    patronContai
}

//---------------------------------------------------------------------------
// addBook
bool Library::buildBooks(istream&) {

}

//---------------------------------------------------------------------------
// displayItems
void Library::displayItems() const {

}

//---------------------------------------------------------------------------
// commandHandler
void Library::commandHandler(istream& in) {

}

//---------------------------------------------------------------------------
//