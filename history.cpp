//---------------------------------------------------------------------------
// history.cpp
//---------------------------------------------------------------------------
// Handles the operation of retrieving the history of a Patron within the
// library system. Returns and outputs their rental history of books from the
// library.
//
// Assumptions:
// -- will only be called on a valid item in the library
//
// Implementation:
//  -- no destructor implementation for dynamic memory in create() method -
//  -- memory deallocation to be handled by Patron class where commands are
//  -- are stored in itemHistory list
//---------------------------------------------------------------------------

#include "history.h"
#include "patroncontainer.h"
#include <iostream>

//---------------------------------------------------------------------------
// constructor
History::History() { commType_ = 'H'; }

//---------------------------------------------------------------------------
// Destructor
History::~History() {}

//---------------------------------------------------------------------------
// execute
bool History::execute() {

    patronPtr_->displayPatron();
    patronPtr_->printHistory();
    return true;
}

//---------------------------------------------------------------------------
// display
void History::display() {}

//---------------------------------------------------------------------------
// create
Command *History::create() { return new History(); }