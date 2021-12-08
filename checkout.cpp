//---------------------------------------------------------------------------
// checkout.h
//---------------------------------------------------------------------------
// Subclass of command.
// Handles checking out a book, will attempt to decrement avaialble copies
// of the book by one.
//
// Assumptions:
// -- will only be called on a valid item in the library
//
// Implementation:
//  -- Execute calls changeAvailable method on Item
//  -- Item to do error handling with available copies
//  -- no destructor implementation for dynamic memory in create() method -
//  -- memory deallocation to be handled by Patron class where commands are
//  -- are stored in itemHistory list
//---------------------------------------------------------------------------

#include "checkout.h"
#include <iostream>

//---------------------------------------------------------------------------
// constructor
Checkout::Checkout() {
    commType_ = 'C';
    item_ = nullptr;
}

//---------------------------------------------------------------------------
// destructor
Checkout::~Checkout() {}

//---------------------------------------------------------------------------
// display
void Checkout::display() {
    cout << "  CheckOut  ";
    item_->historyDisplay();
}

//---------------------------------------------------------------------------
// execute
// item_ data fields are set by command.buildCommand
bool Checkout::execute() {

    // decrement available copies
    return item_->changeAvailable(-1);
}

//---------------------------------------------------------------------------
// create
Command *Checkout::create() { return new Checkout(); }